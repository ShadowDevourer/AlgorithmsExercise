#pragma once
struct SubArray {
	int begin_index;
	int end_index;
	int subarray_element_sum;
	SubArray() {};
	SubArray(int left_index, int right_index, int array_element_sum) :begin_index(left_index), end_index(right_index), subarray_element_sum(array_element_sum){}
};
