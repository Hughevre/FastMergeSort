#include <algorithm>
#include <omp.h>
#include "FastMergeSortAlgorithmOMP.h"

void FastMergeSortAlgorithmOMP::Merge(std::vector<int>& numbers_array,
                                      unsigned int      left_lower_index, 
                                      unsigned int      left_upper_index, 
                                      unsigned int      right_lower_index, 
                                      unsigned int      right_upper_index) const {
    unsigned int length = right_upper_index - left_lower_index + 1;
    unsigned int left   = left_lower_index;
    unsigned int right  = right_lower_index;
    std::vector<int> shuffled_array(length);

    for (unsigned int i = 0; i < length; ++i) {
        if (left > left_upper_index) {
            shuffled_array[i] = numbers_array[right++];
        } else if (right > right_upper_index) {
            shuffled_array[i] = numbers_array[left++];
        } else if (numbers_array[left] <= numbers_array[right]) {
            shuffled_array[i] = numbers_array[left++];
        } else {
            shuffled_array[i] = numbers_array[right++];
        }
    }
    
    /* Copy all values from the temporary array back into original one, starting at left_low */
    for (unsigned int i = 0; i < length; ++i) {
        numbers_array[left_lower_index++] = shuffled_array[i];
    }
}

void FastMergeSortAlgorithmOMP::SortSubArray(std::vector<int>& numbers_array, 
                                             unsigned int      left_index, 
                                             unsigned int      right_index) const {
    if (right_index > left_index) {
        if (right_index - left_index >= 32) {
            unsigned int middle_index = (left_index + right_index) / 2;

            #pragma omp taskgroup
            {
                /* Divide and sort the left subarray */
                #pragma omp task shared(numbers_array) untied if(right_index-left_index >= (1<<14))
                SortSubArray(numbers_array, left_index, middle_index);

                /* Divide and sort the right subarray */
                #pragma omp task shared(numbers_array) untied if(right_index-left_index >= (1<<14))
                SortSubArray(numbers_array, middle_index+1, right_index);

                #pragma omp taskyield
            }

            /* Merge results into single array */
            Merge(numbers_array, left_index, middle_index, middle_index+1, right_index);
        } else {
            /* STL library sorting function used for simplicy. May be replaces by insert sort custom implemetnation */
            std::sort(numbers_array.begin()+left_index, numbers_array.begin()+right_index+1);
        }
    }

    return;
}

/**
 * Sorts an array of integers using merge sort algorithm.
 *
 * The input array is passed by refernce, not by value.
 *
 * @param numbers_array Container whose values are to be sorted.
 */
void FastMergeSortAlgorithmOMP::Sort(std::vector<int>& numbers_array) const {
    #pragma omp parallel
    #pragma omp single
    SortSubArray(numbers_array, 0, numbers_array.size()-1);
}