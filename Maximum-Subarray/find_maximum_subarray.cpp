#include<iostream>
#include"subarray.h"
#include<vector>
#include<limits.h>
#include<stdexcept>
#include<Windows.h>

SubArray FindMaxCrossingSubarray(const std::vector<int> &a,int low,int mid,int high) {
	int left_subarray_sum = INT_MIN;
	int right_subarray_sum = INT_MIN;
	int max_subarray_sum = 0;
	SubArray res;
	if (low == high) {
		res.begin_index = low;
		res.end_index = high;
		return res;
	}
	else {
		int moving_left_index = mid;
		int moving_right_index = mid + 1;
		int sum = 0;
		while (moving_left_index >= low) {
			sum += a[moving_left_index];
			if (sum > left_subarray_sum) {
				left_subarray_sum = sum;
				res.begin_index = moving_left_index;
			}
			moving_left_index--;
		}
		sum = 0;
		while (moving_right_index <= high) {
			sum += a[moving_right_index];
			if (sum > right_subarray_sum) {
				right_subarray_sum = sum;
				res.end_index = moving_right_index;
			}
			moving_right_index++;
		}
		res.subarray_element_sum = left_subarray_sum + right_subarray_sum;
		return res;
	}
}

SubArray FindMaxSubarray(const std::vector<int> &a, int low, int high) {
	if (low == high) {
		SubArray res(low, high, a[low]);
		return res;
	}
	else {
		int mid = (low + high) / 2;
		//����ʧЧ�������ڣ�ÿ�εݹ���ö������������ʼ��
		SubArray max_left_array = FindMaxSubarray(a, low, mid);
		SubArray max_right_array = FindMaxSubarray(a, mid + 1, high);
		SubArray max_crossing_array = FindMaxCrossingSubarray(a, low, mid, high);
		if (max_left_array.subarray_element_sum >= max_right_array.subarray_element_sum&&max_left_array.subarray_element_sum >= max_crossing_array.subarray_element_sum) {
			return max_left_array;
		}
		else if (max_right_array.subarray_element_sum >= max_left_array.subarray_element_sum&&max_right_array.subarray_element_sum >= max_crossing_array.subarray_element_sum) {
			return max_right_array;
		}
		else {
			return max_crossing_array;
		}
	}
}

int main() {
	int amount_of_array_element;
	std::cout << "�����ַ�����ģ��" << std::endl;
	std::cin >> amount_of_array_element;
	std::vector<int> array1(amount_of_array_element);
	SubArray result;
	for (int i = 0; i < (int)array1.size(); i++) {
		std::cin >> array1[i];
	}
	std::cout << std::endl;
	result=FindMaxSubarray(array1, 0, array1.size() - 1);
	for (int i = result.begin_index; i <= result.end_index; i++) {
		std::cout << array1[i] << ' ';
	}
	Sleep(5000);
	std::getchar();
	return 0;
}