#ifndef FAST_MERGE_SORT_ALGORITHM_OMP_H
#define FAST_MERGE_SORT_ALGORITHM_OMP_H

#include <vector>
#include "FastMergeSortAlgorithm.h"

/**
 * The FastMergeSortAlgorithmOMP class implements the merge sort algorithm
 * in a parallelized way using OMP library.
 */
class FastMergeSortAlgorithmOMP : public FastMergeSortAlgorithm {
    public:
        void Sort(std::vector<int>& numbers_array, 
                  unsigned int      left_index, 
                  unsigned int      right_index) const override;

    private:
        void Merge(std::vector<int>& numbers_array,
                   unsigned int      left_lower_index, 
                   unsigned int      left_upper_index, 
                   unsigned int      right_lower_index, 
                   unsigned int      right_upper_index) const override;
};

#endif // FAST_MERGE_SORT_ALGORITHM_OMP_H