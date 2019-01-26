#pragma once
#ifndef HEAP_H
#define HEAP_H
#include<vector>
#include<iostream>
class Heap {
public:
	Heap();
	Heap(std::size_t heap_size,const std::vector<int> &initial_array) {
		heap_size_ = heap_size;
		heap_ = initial_array;
	}
	~Heap();
	std::size_t GetHeapSize() const { return heap_size_; }
	std::size_t GetParentNode(const std::size_t &child_node) const { return (child_node-1) >> 1; }
	std::size_t GetLeftChildNode(const std::size_t &parent_node) const { return (parent_node << 1)+1; }
	std::size_t GetRightChildNode(const std::size_t &parent_node) const { return 2 + (parent_node << 1); }
	std::vector<int> GetHeap() { return heap_; }
	void SetHeapSize(const std::size_t &element_amount) { heap_size_ = element_amount; }
	void MaintenanceMaxHeap(const std::size_t &insert_element);
	void BuildMaxHeap();
	void HeapSort();
	void ShowHeapSortResult();
	void Swap(const std::size_t &a, const std::size_t &b);
private:
	std::vector<int> heap_;
	std::size_t heap_size_;
	bool heap_is_built_ = false;
};
#endif


