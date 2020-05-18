#pragma once
/*
	���鼯
	�±��1��ʼ
	���ڵ�ĸ��ڵ�Ϊ�������Ҿ���ֵΪ���Ĵ�С
	���ڵ�û�и��ڵ㣬��˸��ڵ�ĸ��ڵ�<0
*/
#include <iostream>
#include <map>

template <typename T>
class DisjointSet {
	T* data{ nullptr };
	int* parent{ nullptr };
	int size{ 0 }; // ��������Ԫ��
	int capacity{ 0 }; // ���ϴ�С
	std::map<T, int> m; // ���ڴ洢<data, index>���ݣ������ԣ�dataΪ����indexΪֵ
public:
	DisjointSet(int capacity_);
	// ����Ԫ��
	bool insert(T x);
	// ��ӡ
	void print();
	// �ҵ���ӦԪ�������ĸ����ϣ�����Ԫ�ظ��ڵ��±�
	int find(T x);
	// ����Ԫ�صļ����󲢼�
	void union_set(T x, T y);
};

// ����Ԫ�صļ����󲢼�
template <typename T>
void DisjointSet<T>::union_set(T x, T y) {
	int rx = find(x); // ��x���ϸ��ڵ��±�
	int ry = find(y); // ��y���ϸ��ڵ��±�
	if (rx == 0 || ry == 0) { // ����ڵ㲻����
		return;
	}
	if (rx == ry) { // λ��ͬһ������
		return;
	}
	// ʹ��·��ѹ����С����������
	if (parent[rx] < parent[ry]) { // ���ڵ�parentΪ����������ֵΪ���Ĵ�С
		parent[rx] += parent[ry];
		parent[ry] = rx;
	}
	else {
		parent[ry] += parent[rx];
		parent[rx] = ry;
	}
}

// �ҵ�Ԫ�ؼ���
template <typename T>
int DisjointSet<T>::find(T x) {
	typename std::map<T, int>::iterator it = m.find(x);
	// �ڵ��±��1��ʼ��0λ�ò���Ԫ��
	if (it == m.end()) {
		return 0;
	}

	int root = it->second; // ��¼Ԫ��x���ڵ��±�
	while (parent[root] > 0) {
		root = parent[root];
	}

	// ·��ѹ��
	for (int tmp, i = m[x]; i != root; i = tmp) {
		tmp = parent[i];
		parent[i] = root;
	}

	return root;
}
// ����Ԫ��
template <typename T>
bool DisjointSet<T>::insert(T x) {
	if (size == capacity) {
		return false;
	}
	data[++size] = x;
	parent[size] = -1;
	m[x] = size; // �洢<data, index>�ԣ�������Ҷ�ӦԪ�ص��±�
}

// ��ӡԪ��
template <typename T>
void DisjointSet<T>::print() {
	// ��ӡ�±�
	for (int i = 1; i <= size; ++i) {
		std::cout << i << '\t';
	}
	std::cout << std::endl;
	// ��ӡ���ڵ�
	for (int i = 1; i <= size; ++i) {
		std::cout << parent[i] << '\t';
	}
	std::cout << std::endl;
	// ��ӡֵ
	for (int i = 1; i <= size; ++i) {
		std::cout << data[i] << '\t';
	}
	std::cout << std::endl;
}

// ���캯��
template <typename T>
DisjointSet<T>::DisjointSet(int capacity_) : capacity{ capacity_ }, size{ 0 } {
	data = new T[capacity_ + 1]; // �±��1��ʼ
	parent = new T[capacity_ + 1]; // �±��1��ʼ
}