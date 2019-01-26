#include "heap.h"



Heap::Heap() {
}


Heap::~Heap() {
}

void Heap::MaintenanceMaxHeap(const std::size_t & insert_element) {
	std::size_t left_child_node = GetLeftChildNode(insert_element);
	std::size_t right_child_node = GetRightChildNode(insert_element);
	std::size_t largest_element_node;
	if (left_child_node < GetHeapSize() && heap_[left_child_node] > heap_[insert_element]) {
		largest_element_node = left_child_node;
	}
	else {
		largest_element_node = insert_element;
	}
	if (right_child_node < GetHeapSize() && heap_[right_child_node] > heap_[largest_element_node]) {
		largest_element_node = right_child_node;
	}
	if (largest_element_node != insert_element) {
		Swap(insert_element, largest_element_node);
		MaintenanceMaxHeap(largest_element_node);
	}
}

void Heap::BuildMaxHeap() {
	SetHeapSize(heap_.size());
	for (int i = (heap_size_ >>1) - 1; i >= 0; --i) {
		MaintenanceMaxHeap(i);
	}
	heap_is_built_ = true;
}

void Heap::HeapSort() {
	if (heap_is_built_ != true) {
		BuildMaxHeap();
	}
	for (int i = GetHeapSize() - 1; i >= 1; i--) {
		Swap(0, i);
		heap_size_--;
		MaintenanceMaxHeap(0);
	}
}

void Heap::ShowHeapSortResult() {
	HeapSort();
	for (auto &element : heap_) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

void Heap::Swap(const std::size_t & a, const std::size_t & b) {
	if (a <= heap_size_ && b <= heap_size_) {
		auto temp = heap_[a];
		heap_[a] = heap_[b];
		heap_[b] = temp;
	}
}

