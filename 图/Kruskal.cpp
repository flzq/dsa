#include <string>
#include <iostream>
#include <queue>
#include "Kruskal.h"
using std::string;
using std::cin;
using std::cout;
using std::cout;
using std::endl;
using std::priority_queue;

// kruskal算法
void kruskal() {
	DisjointSet<string> ds;
	priority_queue<Edge> pq; // 建立小顶堆
	vector<Edge> edges;
	string v, w;
	int weight;
	int num_vertex, num_edge; // 顶点数量，边的数量
	cin >> num_vertex;
	// 并查集中加入顶点
	for (int i = 0; i < num_vertex; ++i) {
		cin >> v;
		ds.insert(v);
	}
	// 小顶堆中加入边
	cin >> num_edge;
	for (int i = 0; i < num_edge; ++i) {
		cin >> v >> w >> weight;
		pq.emplace(v, w, weight);
	}
	// kruskal算法
	// 每次选择最小的边
	// 判断边的顶点是否在不同树中
	int count{ 0 }; // 记录MST中边的数量
	Edge e;
	while (!pq.empty()) {
		e = pq.top();
		pq.pop();
		int root1 = ds.find(e.v);
		int root2 = ds.find(e.w);
		if (root1 != root2) { // 不在同一颗树中
			ds.union_set(e.v, e.w);
			++count;
			edges.push_back(e);
		}
	}
	if (count == num_vertex - 1) {
		for (int i = 0; i < edges.size(); ++i) {
			cout << edges[i].v << "-->" << edges[i].w << "(" << edges[i].weight << ") ";
		}
		cout << endl;
	}
	else {
		cout << "图不连通" << endl;
	}
}