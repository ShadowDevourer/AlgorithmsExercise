//归并排序递归算法实现
#include<iostream>
#include<vector>
#include<math.h>
#include<Windows.h>

void Merge(std::vector<int> &a, int begin, int mid, int end) {
	if (end == begin)
		return;
	else {
		std::vector<int> arrayleft;
		std::vector<int> arrayright;
		for (int i = begin; i <= mid; i++) {
			arrayleft.push_back(a[i]);
		}
		for (int j = mid + 1; j <= end; j++) {
			arrayright.push_back(a[j]);
		}
		int left_index = 0;
		int right_index = 0;
		int result_index = begin;
		while (left_index < arrayleft.size() && right_index < arrayright.size()) {
			a[result_index++] = arrayleft[left_index] > arrayright[right_index] ? arrayright[right_index++] : arrayleft[left_index++];
		}
		while (left_index < arrayleft.size()) {
			a[result_index++] = arrayleft[left_index++];
		}
		while (right_index < arrayright.size()) {
			a[result_index++] = arrayright[right_index++];
		}
	}
}
void MergeSort(std::vector<int> &a,int begin,int end) {
	if (1 == end - begin) {
		Merge(a, begin, (end + begin) / 2, end);
		return;
	}
	if (begin < end) {
		int mid = (begin + end) / 2;//?
		MergeSort(a, begin, mid);
		MergeSort(a, mid + 1, end);
		Merge(a, begin, mid, end);
	}
	else
		return;

}
int main() {
	int NumberSize = 0;
	std::cout << "输入待排序数组的规模：" << std::endl;
	std::cin >> NumberSize;
	std::vector<int> a(NumberSize);
	std::vector<int> res(NumberSize);
	std::cout << "输入待排序数组:" << std::endl;
	for (int i = 0; i < NumberSize; i++) {
		std::cin >> a[i];
	}
	std::cout << "待排序数组输入完成" << std::endl;
	MergeSort(a, 0, NumberSize - 1);
	std::cout << "排序后输出序列：" << std::endl;
	auto iter = a.begin();
	while (iter != a.end()) {
		std::cout << *iter;
		iter++;
	}
	std::cout << std::endl;
	Sleep(3000);
	return 0;
}