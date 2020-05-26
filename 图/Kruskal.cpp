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

// kruskal�㷨
void kruskal() {
	DisjointSet<string> ds;
	priority_queue<Edge> pq; // ����С����
	vector<Edge> edges;
	string v, w;
	int weight;
	int num_vertex, num_edge; // �����������ߵ�����
	cin >> num_vertex;
	// ���鼯�м��붥��
	for (int i = 0; i < num_vertex; ++i) {
		cin >> v;
		ds.insert(v);
	}
	// С�����м����
	cin >> num_edge;
	for (int i = 0; i < num_edge; ++i) {
		cin >> v >> w >> weight;
		pq.emplace(v, w, weight);
	}
	// kruskal�㷨
	// ÿ��ѡ����С�ı�
	// �жϱߵĶ����Ƿ��ڲ�ͬ����
	int count{ 0 }; // ��¼MST�бߵ�����
	Edge e;
	while (!pq.empty()) {
		e = pq.top();
		pq.pop();
		int root1 = ds.find(e.v);
		int root2 = ds.find(e.w);
		if (root1 != root2) { // ����ͬһ������
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
		cout << "ͼ����ͨ" << endl;
	}
}