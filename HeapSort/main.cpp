#include"heap.h"

int main() {
	std::vector<int> initial_array;
	std::size_t array_count;
	std::cout << "输入待排序数组的规模：" << std::endl;
	std::cin >> array_count;
	std::cout << std::endl;
	initial_array.resize(array_count);
	for (std::size_t i = 0; i < initial_array.size(); i++) {
		int temp;
		std::cin >> temp;
		initial_array[i] = temp;
	}
	Heap heap_to_sort(initial_array.size(), initial_array);
	heap_to_sort.BuildMaxHeap();
	heap_to_sort.HeapSort();
	heap_to_sort.ShowHeapSortResult();
	return 0;
}