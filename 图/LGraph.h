#pragma once
/*
	邻接表的实现
*/
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include "Graph.h"
using std::string;
using std::vector;
using std::map;
using std::cout;
class LGraph : Graph {
protected:
	vector<map<int, int>> adj_list; // 邻接表
	// 构造邻接表
	void set_adjlist() {
		adj_list.resize(num_vertices);
		for (auto x : adj_list) {
			x.clear();
		}
	}
public:
	LGraph(bool is_dir = false) : Graph(is_dir) {}
	LGraph(vector<string>& v, bool is_dir = false) : Graph(v, is_dir) {
		set_adjlist();
	}
	LGraph(int n, bool is_dir = false) : Graph(n, is_dir) {
		set_adjlist();
	}
	void print() {
		adj_list[0].insert(std::pair<int, int>(1, 99));
		adj_list[1].insert(std::pair<int, int>(2, 88));
		for (int i = 0; i < num_vertices; ++i) {
			cout << vertices[i] << "[" << i << "]-->";
			for (auto x : adj_list[i]) {
				cout << vertices[x.first] << "(" << x.second << ")";
			}
			cout << std::endl;
		}
		cout << std::endl;
	}
	void insert_vertex() {
		insert_vertex(std::to_string(num_vertices));
	}
	bool insert_vertex(string v) {
		Graph::insert_vertex(v);
		// 往邻接表中添加节点

	}
};