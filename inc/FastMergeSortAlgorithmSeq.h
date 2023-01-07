#ifndef FAST_MERGE_SORT_ALGORITHM_SEQ_H
#define FAST_MERGE_SORT_ALGORITHM_SEQ_H

#include <vector>
#include "FastMergeSortAlgorithm.h"

/**
 * The FastMergeSortAlgorithmSeq class implements the merge sort algorithm
 * in a sequential (non-parallel) way.
 */
class FastMergeSortAlgorithmSeq : public FastMergeSortAlgorithm {
    public:
        void Sort(std::vector<int>& numbers_array) const override;

    private:
        void SortSubArray(std::vector<int>& numbers_array, 
                          unsigned int      left_index, 
                          unsigned int      right_index) const override;

        void Merge(std::vector<int>& numbers_array,
                   unsigned int      left_lower_index, 
                   unsigned int      left_upper_index, 
                   unsigned int      right_lower_index, 
                   unsigned int      right_upper_index) const override;
};

#endif // FAST_MERGE_SORT_ALGORITHM_SEQ_H