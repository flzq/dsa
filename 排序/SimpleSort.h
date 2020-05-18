#pragma once
/*
	简单排序类：以整数数组为例进行由小到大的排序
		简单选择排序：selection_sort
		简单插入排序：insertion_sort
		冒泡排序：bubble_sort
*/
#include <iostream>

class SimpleSort {
private:
	int* data{ nullptr };
	int capacity{ 0 };
	void swap(int& x, int& y) {
		int tmp = x;
		x = y;
		y = tmp;
	}

public:
	SimpleSort(int* data_, int capacity_) : capacity{ capacity_ } {
		data = new int[capacity];
		for (int i = 0; i < capacity; ++i) {
			data[i] = data_[i];
		}
	}
	~SimpleSort() {
		delete[] data;
	}
	// 打印数组
	void print() {
		for (int i = 0; i < capacity; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
	// 简单选择排序
	void selection_sort() {
		/*
		    11   33    5   7
		*/
		int min;
		int min_index;
		// 每一趟都选择一个最小值与 i位置交换；一共选择capacity-1趟
		for (int i = 0; i < capacity-1; ++i) { // i 指向当前要换的位置
			min = data[i];
			min_index = i;
			for (int j = i+1; j < capacity; ++j) { // 遍历选择一个最小值，[i, capacity-1] 为查找的最小值的范围
				if (data[j] < min) {
					min = data[j];
					min_index = j;
				}
			}
			if (min_index - i) {
				swap(data[i], data[min_index]);
			}
			std::cout << i+1 << ": ";
			print();
		}
	}
	// 简单插入排序
	void insertion_sort() {
		/*
			5 8 3 11 6
		*/
		for (int i = 1, j; i < capacity; ++i) { // i 指向未排序第一个值的位置
			int tmp = data[i];
			for (j = i; j > 0 && tmp < data[j-1]; --j) { // j指示tmp/data[i]要存放的位置
				data[j] = data[j - 1];
			}
			data[j] = tmp;
			std::cout << i << ": ";
			print();
		}
	}
	// 冒泡排序
	void bubble_sort() {
		int flag = true; // flag=true表示这一趟交换了位置；当有一趟未交换位置，表示全部有序，则flag=false
		for (int i = 0; flag && i < capacity - 1; ++i) { // 最多要排 N-1趟；有flag后  也可以不需要
			// 每次将最大放到后面
			flag = false;
			for (int j = 0; j < capacity-1-i; ++j) { // 排序范围[0, capacity-1-i]
				if (data[j] > data[j + 1]) {
					swap(data[j], data[j + 1]);
					flag = true;
				}
			}
			std::cout << i + 1 << ": ";
			print();
		}
	}
};