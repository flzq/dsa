#pragma once
#include <string>
#include <vector>
#include <map>
using std::vector;
using std::string;
using std::map;
/*
	最小生成树Kruskal算法需要的类的实现
*/

// 并查集
// 下标从0开始
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
		if (m.find(v) != m.end()) { // 已经存在该节点了
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
			return true; // 位于同一棵树上
		}
		parent[root2] = root1;
		return true;
	}
};

// 存储边的信息
struct Edge {
	string v, w;
	int weight;
	bool operator<(const Edge& e) const { // 用于建立小顶堆
		return weight > e.weight;
	}
	Edge() {}
	Edge(string v_, string w_, int weight_) : v{ v_ }, w{ w_ }, weight{ weight_ } {

	}
};

void kruskal();