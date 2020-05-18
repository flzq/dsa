#pragma once
/*
	�������ࣺ����������Ϊ��������С���������
		��ѡ������selection_sort
		�򵥲�������insertion_sort
		ð������bubble_sort
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
	// ��ӡ����
	void print() {
		for (int i = 0; i < capacity; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
	// ��ѡ������
	void selection_sort() {
		/*
		    11   33    5   7
		*/
		int min;
		int min_index;
		// ÿһ�˶�ѡ��һ����Сֵ�� iλ�ý�����һ��ѡ��capacity-1��
		for (int i = 0; i < capacity-1; ++i) { // i ָ��ǰҪ����λ��
			min = data[i];
			min_index = i;
			for (int j = i+1; j < capacity; ++j) { // ����ѡ��һ����Сֵ��[i, capacity-1] Ϊ���ҵ���Сֵ�ķ�Χ
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
	// �򵥲�������
	void insertion_sort() {
		/*
			5 8 3 11 6
		*/
		for (int i = 1, j; i < capacity; ++i) { // i ָ��δ�����һ��ֵ��λ��
			int tmp = data[i];
			for (j = i; j > 0 && tmp < data[j-1]; --j) { // jָʾtmp/data[i]Ҫ��ŵ�λ��
				data[j] = data[j - 1];
			}
			data[j] = tmp;
			std::cout << i << ": ";
			print();
		}
	}
	// ð������
	void bubble_sort() {
		int flag = true; // flag=true��ʾ��һ�˽�����λ�ã�����һ��δ����λ�ã���ʾȫ��������flag=false
		for (int i = 0; flag && i < capacity - 1; ++i) { // ���Ҫ�� N-1�ˣ���flag��  Ҳ���Բ���Ҫ
			// ÿ�ν����ŵ�����
			flag = false;
			for (int j = 0; j < capacity-1-i; ++j) { // ����Χ[0, capacity-1-i]
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