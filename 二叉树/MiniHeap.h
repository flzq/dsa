#pragma once
/*
	最小堆的实现
	使用数组实现堆
	下标从1开始
*/
#include <iostream>

template <typename T>
class MiniHeap {
private:
	T* data{ nullptr };
	int capacity{ 0 }; // 堆的容量
	int size{ 0 }; // 堆现有元素

	// 上滤
	void percolate_up(int pos);
	// 下滤
	void percolate_down(int pos);
public:
	MiniHeap(int capacity_);
	// 使用列表建立最小堆
	MiniHeap(T a[], int size_, int capacity_);
	~MiniHeap();

	// 最小堆的插入
	bool insert(T x);
	// 最小堆的删除
	bool remove(T& x);
	// 打印堆
	void print();
};

// 最小堆的删除
template <typename T>
bool MiniHeap<T>::remove(T& x) {
	if (size == 0) {
		return false;
	}
	x = data[1];
	data[1] = data[size--];
	percolate_down(1);
	return true;
}
// 下滤
template <typename T>
void MiniHeap<T>::percolate_down(int pos) {
	// 位置pos处的元素下滤
	T x = data[pos];
	int i, child;
	for (i = pos; i * 2 <= size; i = child) {
		child = i * 2;
		if ((child + 1) <= size && data[child] > data[child + 1]) {
			++child;
		}
		if (x > data[child]) {
			data[i] = data[child];
		}
		else {
			break;
		}
	}
	data[i] = x;
}

// 最小堆的插入
template <typename T>
bool MiniHeap<T>::insert(T x) {
	if (size == capacity) { // 堆满了
		return false;
	}

	data[++size] = x; // 插入到数组末尾
	// 上滤
	percolate_up(size);
	return true;
}
// 上滤
template <typename T>
void MiniHeap<T>::percolate_up(int pos) {
	T x = data[pos];
	int i;
	for (i = pos; i > 1 && x < data[i / 2]; i /= 2) {
		data[i] = data[i / 2];
	}
	data[i] = x;
}

// 构造函数
template <typename T>
MiniHeap<T>::MiniHeap(int capacity_) {
	capacity = capacity_;
	size = 0;
	data = new T[capacity + 1]; // 因为下标从1开始
}
// 使用列表构建堆
template <typename T>
MiniHeap<T>::MiniHeap(T a[], int size_, int capacity_) : MiniHeap(capacity_) {	// 先调用MiniHeap(int capacity_)构造函数
	size = size_;
	// 堆中复制数组元素
	for (int i = 1; i <= size; ++i) {
		data[i] = a[i - 1];
	}
	// 对堆中的元素进行下滤
	for (int i = size / 2; i > 0; --i) {
		percolate_down(i);
	}
}
// 析构函数
template <typename T>
MiniHeap<T>::~MiniHeap() {
	delete[] data;
}

// 打印堆
template <typename T>
void MiniHeap<T>::print() {
	for (int i = 1; i < size + 1; ++i) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}