#pragma once
/*
	堆排序：对数组由小到大排序
	堆：建立大顶堆
	以整数数组排序为例
	使用到优先队列中的下滤
	额外空间：不适用其他数组存储排好序的值，在原数组进行操作
	堆排序数组下标从0开始：
			找左儿子：2i+1；
			找右儿子：2i+2；
			找父亲：（i+1）/2 - 1（但是树根时，(0+1)/2-1=-1，可以用负数判断是根节点，没有父节点）

*/
#include <iostream>
class HeapSort {
private:
	int* data{ nullptr };
	int size{ 0 }; // 堆含有的数据
	void percolate_down(int pos, int size_) {
		/*
			size_：下滤的范围，待排序数组的大小
			下标从0开始，数组范围：[0, size_-1]
		*/
		int tmp = data[pos];
		int child, i;
		for (i = pos; (2 * i + 1) < size_; i = child) {
			/*
				i 表示当前要下滤的元素的索引
				建立大顶堆
			*/
			child = 2 * i + 1; // 左儿子
			if (child != (size_ - 1) && data[child] < data[child + 1]) { // 是否有右儿子
				++child;
			}
			if (tmp < data[child]) {
				data[i] = data[child];
			}
			else {
				break;
			}
		}
		data[i] = tmp;
	}
	void swap(int& x, int& y) {
		int tmp = x;
		x = y;
		y = tmp;
	}
public:
	HeapSort(int* data_, int size_) : data{ data_ }, size{ size_ } {
		// 建立堆：使用下滤建立大顶堆(用于由小到大排序)
		// 下标从0开始
		for (int i = size / 2 - 1; i >= 0; --i) {
			percolate_down(i, size);
		}
		// 堆排序
	}
	// 堆排序
	void heapsort() {
		for (int i = size - 1; i > 0; --i) {
			swap(data[0], data[i]); // 每一次都把最大值放到最后
			percolate_down(0, i);
			std::cout << size - i << ": ";
			print();
		}
	}
	void print() {
		for (int i = 0; i < size; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};
