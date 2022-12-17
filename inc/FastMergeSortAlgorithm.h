#ifndef FAST_MERGE_SORT_ALGORITHM_H
#define FAST_MERGE_SORT_ALGORITHM_H

#include <vector>

class FastMergeSortAlgorithm {
    public:
        FastMergeSortAlgorithm() = delete;

        static void Sort(std::vector<int>& numbers_array, 
                         unsigned int      left_index, 
                         unsigned int      right_index);

    private:
        static void Merge(std::vector<int>& numbers_array,
                          unsigned int      left_lower_index, 
                          unsigned int      left_upper_index, 
                          unsigned int      right_lower_index, 
                          unsigned int      right_upper_index);
};

#endif // FAST_MERGE_SORT_ALGORITHM_H