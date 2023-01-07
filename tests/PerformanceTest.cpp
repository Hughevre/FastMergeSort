#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include <memory>
#include <algorithm>
#include <random>
#include <catch2/catch.hpp>
#include "FastMergeSortAlgorithmTestCtx.h"
#include "../inc/FastMergeSortAlgorithmSeq.h"
#include "../inc/FastMergeSortAlgorithmOMP.h"

TEST_CASE("Benchmark test", "[main]") {
    /* Create empty vectors to be sorted */
    const unsigned int numbers_array_length = 5000000;
    std::vector<int>   array_sorted_by_fms(numbers_array_length);

    /* Create some objects used in randomization */
    const unsigned int              u_distribution_lower_bound = -(10 * numbers_array_length) - 1;
    const unsigned int              u_distribution_upper_bound = 10 * numbers_array_length;
    std::random_device              rnd_device;
    std::mt19937                    mersenne_engine(rnd_device());
    std::uniform_int_distribution<> u_distribution(u_distribution_lower_bound, u_distribution_upper_bound);

    /* Create test context */
    FastMergeSortAlgorithmTestCtx test_ctx(std::make_unique<FastMergeSortAlgorithmSeq>());

    /* Populate both arrays by some random values */
    std::generate(array_sorted_by_fms.begin(), array_sorted_by_fms.end(), [&]{ return u_distribution(mersenne_engine); });

    BENCHMARK("Sequential implementation") {
        test_ctx.RunPhase(array_sorted_by_fms);
    }; // <- SEMICOLON

    test_ctx.SetAlgorithm(std::make_unique<FastMergeSortAlgorithmOMP>());
    std::shuffle(array_sorted_by_fms.begin(), array_sorted_by_fms.end(), mersenne_engine);

    BENCHMARK("OpenMP implementation") {
            test_ctx.RunPhase(array_sorted_by_fms);
    }; // <- SEMICOLON
}