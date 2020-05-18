#pragma once
#include <iostream>
// 记录hash表中节点的状态：空，有值，值被删除
enum Status {Empty, Activated, Deleted};

// 暂时考虑整型
class HashTable {
	int* key{ nullptr };
	Status* status{ nullptr };
	int capacity{ 0 }; // 哈希表的容量
	int remains{ 0 }; // 哈希表中还剩多少空节点

public:
	// 构造函数
	HashTable(int capacity_) : capacity{ capacity_ }, remains{ capacity_ } {
		key = new int[capacity];
		status = new Status[capacity];
		for (int i = 0; i < capacity; ++i) {
			status[i] = Empty;
		}
	}
	// 析构函数
	~HashTable() {
		delete[] key;
		delete[] status;
	}
	// 哈希函数：求模取余，p=capacity
	int hash(int x) {
		return x % capacity;
	}
	// 判断哈希表是否满
	bool is_full() {
		return remains == 0;
	}
	// 插入
	// 解决冲突：采用开放定址法中的线性探测
	bool insert(int x) {
		if (is_full()) { // 没有位置则不能插入
			return false;
		}
		int pos = hash(x);
		while (status[pos] == Activated) { // Deleted和Empty处都可以插入
			pos = hash(pos + 1);
		}
		key[pos] = x;
		status[pos] = Activated;
		--remains;
	}
	// 查找
	int find(int x) {
		int pos, index; // index存储第一次计算得到的地址
		pos= index = hash(x);
		while (status[pos] != Empty) {
			if (key[pos] == x && status[pos] == Activated) {
				return pos;
			}
			pos = hash(pos + 1);
			// 判断是否循环一遍了，是：退出
			if (pos == index) {
				break;
			}
		}

		return -1;
	}
	// 删除
	bool remove(int x) {
		int index = find(x);
		if (index == -1) {
			// 没有该元素
			return false;
		}
		status[index] = Deleted;
		--remains; // 删除后，该位置标记为Deleted，但可以插入
	}
	// 打印
	void print() {
		for (int i = 0; i < capacity; ++i) {
			std::cout << i << '\t';
		}
		std::cout << std::endl;
		for (int i = 0; i < capacity; ++i) {
			if (status[i] == Activated) {
				std::cout << key[i] << '\t';
			}
			else if (status[i] == Deleted) {
				std::cout << "x" << '\t';
			}
			else {
				std::cout << "-" << '\t';
			}
		}
		std::cout << std::endl;
	}
};