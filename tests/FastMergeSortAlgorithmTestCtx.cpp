#include <iostream>
#include "FastMergeSortAlgorithmTestCtx.h"

/**
 * Explicitly stated move ctor.
*/
FastMergeSortAlgorithmTestCtx::FastMergeSortAlgorithmTestCtx(std::unique_ptr<FastMergeSortAlgorithm>&& algorithm_flavour) :
            algorithm_flavour_(std::move(algorithm_flavour)) {
}

/**
 * Allows replacing currently set algorithm flavour by the new one.
 * 
 * @param algorithm_flavour Reference to the new algorithm type.
 */
void FastMergeSortAlgorithmTestCtx::SetAlgorithm(std::unique_ptr<FastMergeSortAlgorithm>&& algorithm_flavour) {
    algorithm_flavour_ = std::move(algorithm_flavour);
}

/**
 * Does the main work.
 * 
 * @param numbers_array Container whose values are to be sorted.
 * @param left_index    The beggining of the subarray that is to be sorted.
 * @param right_index   The end of the subarray that is to be sorted.
 */
void FastMergeSortAlgorithmTestCtx::RunPhase(std::vector<int>& numbers_array,
                                             unsigned int      left_index,
                                             unsigned int      right_index) const {
    if (!algorithm_flavour_) {
        std::cout << "[ERROR] The specific algorithm type has not been set!" << std::endl;
        return;
    }

    algorithm_flavour_->Sort(numbers_array, left_index, right_index);
}

