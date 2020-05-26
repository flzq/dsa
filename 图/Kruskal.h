#pragma once
#include <string>
#include <vector>
#include <map>
using std::vector;
using std::string;
using std::map;
/*
	��С������Kruskal�㷨��Ҫ�����ʵ��
*/

// ���鼯
// �±��0��ʼ
template<typename T>
class DisjointSet {
	vector<T> data;
	vector<int> parent;
	int size{ 0 };
	map<T, int> m;
public:
	DisjointSet() : size{ 0 } {

	}
	bool insert(T v) {
		if (m.find(v) != m.end()) { // �Ѿ����ڸýڵ���
			return true;
		}
		data.push_back(v);
		parent.push_back(-1);
		m[v] = size++;
		return true;
	}
	int find(T v) {
		if (m.find(v) == m.end()) {
			return -1;
		}
		int root = m[v];
		while (parent[root] != -1) {
			root = parent[root];
		}
		return root;
	}
	bool union_set(T v, T w) {
		int root1 = find(v);
		int root2 = find(w);
		if (root1 == -1 || root2 == -1) {
			return false;
		}
		if (root1 == root2) {
			return true; // λ��ͬһ������
		}
		parent[root2] = root1;
		return true;
	}
};

// �洢�ߵ���Ϣ
struct Edge {
	string v, w;
	int weight;
	bool operator<(const Edge& e) const { // ���ڽ���С����
		return weight > e.weight;
	}
	Edge() {}
	Edge(string v_, string w_, int weight_) : v{ v_ }, w{ w_ }, weight{ weight_ } {

	}
};

void kruskal();