#include<iostream>
#include<vector>

void Swap(const std::size_t &a, const std::size_t &b, std::vector<int> &array_to_swap) {
	if (a <= array_to_swap.size() && b <= array_to_swap.size()) {
		auto temp = array_to_swap[a];
		array_to_swap[a] = array_to_swap[b];
		array_to_swap[b] = temp;
	}
}

int Parttion(const int &start, const int &end, std::vector<int> &array_to_apart) {
	auto boundary_element = array_to_apart[end];
	int sentinel = start - 1;
	for (int i = start; i < end; i++) {
		if (array_to_apart[i] < boundary_element) {
			sentinel++;
			Swap(sentinel, i, array_to_apart);
		}
	}
	Swap(++sentinel, end, array_to_apart);
	return sentinel;
}
void QuickSort(const int &start, const int &end,std::vector<int> &array_to_sort) {
	if (start < end) {
		int sentinel = Parttion(start, end, array_to_sort);
		QuickSort(start, sentinel-1, array_to_sort);
		QuickSort(sentinel + 1, end, array_to_sort);
	}
}

int main() {
	std::vector<int> initial_array;
	std::size_t array_element_count;
	std::cout << "输入待排序数组规模：" << std::endl;
	std::cin >> array_element_count;
	std::cout << std::endl;
	initial_array.resize(array_element_count);
	std::cout << "输入数组元素：" << std::endl;
	for (std::size_t i = 0; i < initial_array.size(); i++) {
		int temp = 0;
		std::cin >> temp;
		initial_array[i] = temp;
	}
	QuickSort(0, initial_array.size() - 1, initial_array);
	std::cout << "排序后的数组：" << std::endl;
	for (auto &element : initial_array) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
	return 0;
}