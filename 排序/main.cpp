#include <iostream>
#include "SimpleSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

void test_simplesort(int* data, int size) {
	SimpleSort ss{ data, size };
	std::cout << 0 << ": ";
	ss.print();
	// ss.selection_sort();
	// ss.insertion_sort();
	ss.bubble_sort();
	ss.print();
}

void test_heapsort(int* data, int size) {
	HeapSort hs{data, size };
	std::cout << 0 << ": ";
	hs.print();
	hs.heapsort();
}

void test_mergesort(int* data, int size) {
	MergeSort ms{ data, size };
	ms.merge_sort();
	ms.print();
}

void test_quicksort(int* data, int size) {
	quick_sort(data, size);
	for (int i = 0; i < size; ++i) {
		printf("%d ", data[i]);
	}
}

//int main() {
//	// test_simplesort(data, 6);
//	/*int data[]{ 5, 4, 6, 9, 0, 33, -5,  999, -100};
//	test_heapsort(data, 9);
//	std::cout << "=============" << std::endl;
//	int data2[]{ 5, 4, 6, 9, 0, 33, -5,  999, -100 };
//	test_mergesort(data2, 9);*/
//	int data3[]{ 0, 3, 3, 3, 4 };
//	test_quicksort(data3, 5);
//	return 0;
//}