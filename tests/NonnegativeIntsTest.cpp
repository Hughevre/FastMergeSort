#include <memory>
#include <algorithm>
#include <random>
#include <catch2/catch.hpp>
#include "FastMergeSortAlgorithmTestCtx.h"
#include "../inc/FastMergeSortAlgorithmSeq.h"
#include "../inc/FastMergeSortAlgorithmOMP.h"

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

    SECTION("Correctness check for sequential imp.") {
        /* Sort the arrays using tho different methods */
        test_ctx.RunPhase(array_sorted_by_fms);
        std::sort(array_sorted_by_std.begin(), array_sorted_by_std.end());

        /* Compare the results */
        REQUIRE(array_sorted_by_fms == array_sorted_by_std);
    }

    /* Shuffle both arrays so that they are ready for new play */
    std::shuffle(array_sorted_by_fms.begin(), array_sorted_by_fms.end(), mersenne_engine);
    array_sorted_by_std = array_sorted_by_fms;

    SECTION("Correctness check for OMP imp.") {
        /* Sort the arrays using tho different methods */
        test_ctx.SetAlgorithm(std::make_unique<FastMergeSortAlgorithmOMP>());
        test_ctx.RunPhase(array_sorted_by_fms);
        std::sort(array_sorted_by_std.begin(), array_sorted_by_std.end());

        /* Compare the results */
        REQUIRE(array_sorted_by_fms == array_sorted_by_std);
    }
}
