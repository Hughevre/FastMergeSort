#ifndef FAST_MERGE_SORT_ALGORITHM_H
#define FAST_MERGE_SORT_ALGORITHM_H

#include <vector>

/**
 * The FastMergeSortAlgorithm interface declares operations common to all supported versions
 * of merge sort algorithm. 
 */
class FastMergeSortAlgorithm {
    public:
        virtual void Sort(std::vector<int>& numbers_array, 
                          unsigned int      left_index, 
                          unsigned int      right_index) const = 0;

    protected:
        virtual void Merge(std::vector<int>& numbers_array,
                           unsigned int      left_lower_index, 
                           unsigned int      left_upper_index, 
                           unsigned int      right_lower_index, 
                           unsigned int      right_upper_index) const = 0;
};

#endif // FAST_MERGE_SORT_ALGORITHM_H