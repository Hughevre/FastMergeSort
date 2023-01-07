#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include <memory>
#include <algorithm>
#include <random>
#include <catch2/catch.hpp>
#include "FastMergeSortAlgorithmTestCtx.h"
#include "../inc/FastMergeSortAlgorithmSeq.h"

TEST_CASE("Nonnegative numbers check", "[main]") {
    /* Create empty vectors to be sorted */
    const unsigned int numbers_array_length = 500000;
    std::vector<int>   array_sorted_by_fms(numbers_array_length);
    std::vector<int>   array_sorted_by_std;

    /* Create some objects used in randomization */
    const unsigned int              u_distribution_lower_bound = 0;
    const unsigned int              u_distribution_upper_bound = 10 * numbers_array_length;
    std::random_device              rnd_device;
    std::mt19937                    mersenne_engine(rnd_device());
    std::uniform_int_distribution<> u_distribution(u_distribution_lower_bound, u_distribution_upper_bound);

    /* Create test context */
    FastMergeSortAlgorithmTestCtx test_ctx(std::make_unique<FastMergeSortAlgorithmSeq>());

    /* Populate both arrays by some random values */
    std::generate(array_sorted_by_fms.begin(), array_sorted_by_fms.end(), [&]{ return u_distribution(mersenne_engine); });
    array_sorted_by_std = array_sorted_by_fms;

    /* Sort the arrays using tho different methods */
    test_ctx.RunPhase(array_sorted_by_fms, 0, array_sorted_by_fms.size()-1);
    std::sort(array_sorted_by_std.begin(), array_sorted_by_std.end());

    SECTION("Correctness check") {
        /* Compare the results */
        REQUIRE(array_sorted_by_fms == array_sorted_by_std);
    }

    SECTION("Performance check") {
        std::shuffle(array_sorted_by_fms.begin(), array_sorted_by_fms.end(), mersenne_engine);
        std::shuffle(array_sorted_by_std.begin(), array_sorted_by_std.end(), mersenne_engine);

        BENCHMARK("FastMergeSort implementation") {
            test_ctx.RunPhase(array_sorted_by_fms, 0, array_sorted_by_fms.size()-1);
        }; // <- SEMICOLON

        BENCHMARK("STD library implementation") {
            std::sort(array_sorted_by_std.begin(), array_sorted_by_std.end());
        }; // <- SEMICOLON
    }
}
