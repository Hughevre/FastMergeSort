#include "FastMergeSortAlgorithmSeq.h"

void FastMergeSortAlgorithmSeq::Merge(std::vector<int>& numbers_array,
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

void FastMergeSortAlgorithmSeq::SortSubArray(std::vector<int>& numbers_array, 
                                             unsigned int      left_index, 
                                             unsigned int      right_index) const {
    if (right_index > left_index) {
        unsigned int middle_index = (left_index + right_index) / 2;

        /* Divide and sort the left subarray */
        SortSubArray(numbers_array, left_index, middle_index);

        /* Divide and sort the right subarray */
        SortSubArray(numbers_array, middle_index+1, right_index);

        /* Merge results into single array */
        Merge(numbers_array, left_index, middle_index, middle_index+1, right_index);
    }

    return;
}

/**
 * Sorts an array of integers using merge sort algorithm.
 *
 * The input array is passed by refernce, not by value.
 * The whole array is to be sorted.
 *
 * @param numbers_array Container whose values are to be sorted.
 */
void FastMergeSortAlgorithmSeq::Sort(std::vector<int>& numbers_array) const {
    SortSubArray(numbers_array, 0, numbers_array.size()-1);
}
