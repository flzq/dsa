#pragma once
/*
	��С�ѵ�ʵ��
	ʹ������ʵ�ֶ�
	�±��1��ʼ
*/
#include <iostream>

template <typename T>
class MiniHeap {
private:
	T* data{ nullptr };
	int capacity{ 0 }; // �ѵ�����
	int size{ 0 }; // ������Ԫ��

	// ����
	void percolate_up(int pos);
	// ����
	void percolate_down(int pos);
public:
	MiniHeap(int capacity_);
	// ʹ���б�����С��
	MiniHeap(T a[], int size_, int capacity_);
	~MiniHeap();

	// ��С�ѵĲ���
	bool insert(T x);
	// ��С�ѵ�ɾ��
	bool remove(T& x);
	// ��ӡ��
	void print();
};

// ��С�ѵ�ɾ��
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
// ����
template <typename T>
void MiniHeap<T>::percolate_down(int pos) {
	// λ��pos����Ԫ������
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

// ��С�ѵĲ���
template <typename T>
bool MiniHeap<T>::insert(T x) {
	if (size == capacity) { // ������
		return false;
	}

	data[++size] = x; // ���뵽����ĩβ
	// ����
	percolate_up(size);
	return true;
}
// ����
template <typename T>
void MiniHeap<T>::percolate_up(int pos) {
	T x = data[pos];
	int i;
	for (i = pos; i > 1 && x < data[i / 2]; i /= 2) {
		data[i] = data[i / 2];
	}
	data[i] = x;
}

// ���캯��
template <typename T>
MiniHeap<T>::MiniHeap(int capacity_) {
	capacity = capacity_;
	size = 0;
	data = new T[capacity + 1]; // ��Ϊ�±��1��ʼ
}
// ʹ���б�����
template <typename T>
MiniHeap<T>::MiniHeap(T a[], int size_, int capacity_) : MiniHeap(capacity_) {	// �ȵ���MiniHeap(int capacity_)���캯��
	size = size_;
	// ���и�������Ԫ��
	for (int i = 1; i <= size; ++i) {
		data[i] = a[i - 1];
	}
	// �Զ��е�Ԫ�ؽ�������
	for (int i = size / 2; i > 0; --i) {
		percolate_down(i);
	}
}
// ��������
template <typename T>
MiniHeap<T>::~MiniHeap() {
	delete[] data;
}

// ��ӡ��
template <typename T>
void MiniHeap<T>::print() {
	for (int i = 1; i < size + 1; ++i) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}