#pragma once
/*
	�����򣺶�������С��������
	�ѣ������󶥶�
	��������������Ϊ��
	ʹ�õ����ȶ����е�����
	����ռ䣺��������������洢�ź����ֵ����ԭ������в���
	�����������±��0��ʼ��
			������ӣ�2i+1��
			���Ҷ��ӣ�2i+2��
			�Ҹ��ף���i+1��/2 - 1����������ʱ��(0+1)/2-1=-1�������ø����ж��Ǹ��ڵ㣬û�и��ڵ㣩

*/
#include <iostream>
class HeapSort {
private:
	int* data{ nullptr };
	int size{ 0 }; // �Ѻ��е�����
	void percolate_down(int pos, int size_) {
		/*
			size_�����˵ķ�Χ������������Ĵ�С
			�±��0��ʼ�����鷶Χ��[0, size_-1]
		*/
		int tmp = data[pos];
		int child, i;
		for (i = pos; (2 * i + 1) < size_; i = child) {
			/*
				i ��ʾ��ǰҪ���˵�Ԫ�ص�����
				�����󶥶�
			*/
			child = 2 * i + 1; // �����
			if (child != (size_ - 1) && data[child] < data[child + 1]) { // �Ƿ����Ҷ���
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
		// �����ѣ�ʹ�����˽����󶥶�(������С��������)
		// �±��0��ʼ
		for (int i = size / 2 - 1; i >= 0; --i) {
			percolate_down(i, size);
		}
		// ������
	}
	// ������
	void heapsort() {
		for (int i = size - 1; i > 0; --i) {
			swap(data[0], data[i]); // ÿһ�ζ������ֵ�ŵ����
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
