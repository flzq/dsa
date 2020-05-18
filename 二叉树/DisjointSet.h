#pragma once
/*
	并查集
	下标从1开始
	根节点的父节点为负数，且绝对值为树的大小
	根节点没有父节点，因此根节点的父节点<0
*/
#include <iostream>
#include <map>

template <typename T>
class DisjointSet {
	T* data{ nullptr };
	int* parent{ nullptr };
	int size{ 0 }; // 集合现有元素
	int capacity{ 0 }; // 集合大小
	std::map<T, int> m; // 用于存储<data, index>数据，索引对，data为键，index为值
public:
	DisjointSet(int capacity_);
	// 插入元素
	bool insert(T x);
	// 打印
	void print();
	// 找到相应元素属于哪个集合，返回元素根节点下标
	int find(T x);
	// 两个元素的集合求并集
	void union_set(T x, T y);
};

// 两个元素的集合求并集
template <typename T>
void DisjointSet<T>::union_set(T x, T y) {
	int rx = find(x); // 求x集合根节点下标
	int ry = find(y); // 求y集合根节点下标
	if (rx == 0 || ry == 0) { // 任意节点不存在
		return;
	}
	if (rx == ry) { // 位于同一颗树上
		return;
	}
	// 使用路径压缩，小树并到大树
	if (parent[rx] < parent[ry]) { // 根节点parent为负数，绝对值为树的大小
		parent[rx] += parent[ry];
		parent[ry] = rx;
	}
	else {
		parent[ry] += parent[rx];
		parent[rx] = ry;
	}
}

// 找到元素集合
template <typename T>
int DisjointSet<T>::find(T x) {
	typename std::map<T, int>::iterator it = m.find(x);
	// 节点下标从1开始，0位置不放元素
	if (it == m.end()) {
		return 0;
	}

	int root = it->second; // 记录元素x根节点下标
	while (parent[root] > 0) {
		root = parent[root];
	}

	// 路径压缩
	for (int tmp, i = m[x]; i != root; i = tmp) {
		tmp = parent[i];
		parent[i] = root;
	}

	return root;
}
// 插入元素
template <typename T>
bool DisjointSet<T>::insert(T x) {
	if (size == capacity) {
		return false;
	}
	data[++size] = x;
	parent[size] = -1;
	m[x] = size; // 存储<data, index>对，方便查找对应元素的下标
}

// 打印元素
template <typename T>
void DisjointSet<T>::print() {
	// 打印下标
	for (int i = 1; i <= size; ++i) {
		std::cout << i << '\t';
	}
	std::cout << std::endl;
	// 打印父节点
	for (int i = 1; i <= size; ++i) {
		std::cout << parent[i] << '\t';
	}
	std::cout << std::endl;
	// 打印值
	for (int i = 1; i <= size; ++i) {
		std::cout << data[i] << '\t';
	}
	std::cout << std::endl;
}

// 构造函数
template <typename T>
DisjointSet<T>::DisjointSet(int capacity_) : capacity{ capacity_ }, size{ 0 } {
	data = new T[capacity_ + 1]; // 下标从1开始
	parent = new T[capacity_ + 1]; // 下标从1开始
}