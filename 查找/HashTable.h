#pragma once
#include <iostream>
// ��¼hash���нڵ��״̬���գ���ֵ��ֵ��ɾ��
enum Status {Empty, Activated, Deleted};

// ��ʱ��������
class HashTable {
	int* key{ nullptr };
	Status* status{ nullptr };
	int capacity{ 0 }; // ��ϣ�������
	int remains{ 0 }; // ��ϣ���л�ʣ���ٿսڵ�

public:
	// ���캯��
	HashTable(int capacity_) : capacity{ capacity_ }, remains{ capacity_ } {
		key = new int[capacity];
		status = new Status[capacity];
		for (int i = 0; i < capacity; ++i) {
			status[i] = Empty;
		}
	}
	// ��������
	~HashTable() {
		delete[] key;
		delete[] status;
	}
	// ��ϣ��������ģȡ�࣬p=capacity
	int hash(int x) {
		return x % capacity;
	}
	// �жϹ�ϣ���Ƿ���
	bool is_full() {
		return remains == 0;
	}
	// ����
	// �����ͻ�����ÿ��Ŷ�ַ���е�����̽��
	bool insert(int x) {
		if (is_full()) { // û��λ�����ܲ���
			return false;
		}
		int pos = hash(x);
		while (status[pos] == Activated) { // Deleted��Empty�������Բ���
			pos = hash(pos + 1);
		}
		key[pos] = x;
		status[pos] = Activated;
		--remains;
	}
	// ����
	int find(int x) {
		int pos, index; // index�洢��һ�μ���õ��ĵ�ַ
		pos= index = hash(x);
		while (status[pos] != Empty) {
			if (key[pos] == x && status[pos] == Activated) {
				return pos;
			}
			pos = hash(pos + 1);
			// �ж��Ƿ�ѭ��һ���ˣ��ǣ��˳�
			if (pos == index) {
				break;
			}
		}

		return -1;
	}
	// ɾ��
	bool remove(int x) {
		int index = find(x);
		if (index == -1) {
			// û�и�Ԫ��
			return false;
		}
		status[index] = Deleted;
		--remains; // ɾ���󣬸�λ�ñ��ΪDeleted�������Բ���
	}
	// ��ӡ
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