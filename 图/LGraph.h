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

	// 深度优先搜索
	virtual void dfs(int v) {
		cout << vertices[v] << " ";
		visited[v] = true;
		for (auto x : adj_list[v]) {
			if (visited[x.first] == false) {
				dfs(x.first);
			}
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
		for (int i = 0; i < num_vertices; ++i) {
			cout << vertices[i] << "[" << i << "]-->";
			for (auto x : adj_list[i]) {
				cout << vertices[x.first] << "(" << x.second << ")";
			}
			cout << std::endl;
		}
		cout << std::endl;
	}
	// 插入节点
	void insert_vertex() {
		insert_vertex(std::to_string(num_vertices));
	}
	bool insert_vertex(string v) {
		bool tmp = Graph::insert_vertex(v);
		if (tmp == false) {
			return false;
		}
		// 往邻接表中添加节点
		adj_list.push_back(map<int, int>());
		return true;
	}
	// 插入边
	bool insert_edge(string v_begin, string v_end, int weight = 1) {
		/*
			v_begin: 开始节点
			v_end: 结束节点
		*/
		return Graph::insert_edge(v_begin, v_end, weight); // 在Graph中会调用bool insert_edge(int src, int dst, int weight = 1)
	}
	// 通过节点编号插入边，只可用于插入已有节点的边
	bool insert_edge(int src, int dst, int weight = 1) {
		/*
			src: 开始节点编号
			dst: 结束节点编号
		*/
		// 若直接调用该函数，判断节点是否存在，如果节点不存在，则不能插入
		if (src < 0 || src >= num_vertices || dst < 0 || dst >= num_vertices) {
			return false;
		}
		// 判断是否存在边
		if (adj_list[src].find(dst) != adj_list[src].end()) {
			// 边已经存在
			return false;
		}
		// 插入边
		adj_list[src].insert(std::pair<int, int>(dst, weight));
		if (is_directed == false) {
			adj_list[dst].insert(std::pair<int, int>(src, weight));
		}
		return true;
	}

	// 删除边
	virtual bool remove_edge(string src, string dst) {
		return Graph::remove_edge(src, dst);
	}
	virtual bool remove_edge(int src, int dst) {
		// 若直接调用该函数，判断节点是否存在，如果节点不存在，则不能删除
		if (src < 0 || src >= num_vertices || dst < 0 || dst >= num_vertices) {
			return false;
		}
		// 如果没有边，则不能删除
		if (adj_list[src].find(dst) == adj_list[src].end()) {
			return false;
		}
		adj_list[src].erase(dst);
		if (is_directed == false) {
			adj_list[dst].erase(src);
		}
		return true;
	}

	// 查找边
	virtual bool find_edge(string src, string dst) {
		return Graph::find_edge(src, dst);
	}
	virtual bool find_edge(int src, int dst) {
		// 若直接调用该函数，判断节点是否存在，如果节点不存在，则无法查找
		if (src < 0 || src >= num_vertices || dst < 0 || dst >= num_vertices) {
			return false;
		}
		// 判断边是否存在
		// 不存在，返回false
		if (adj_list[src].find(dst) == adj_list[src].end()) {
			return false;
		}
		return true;
	}

	// 深度优先搜索
	virtual void dfs(string v) {
		Graph::dfs(v);
	}

	// 广度优先搜索
	void bfs(string v) {
		if (ver_index.find(v) == ver_index.end()) {
			return;
		}
		visited.resize(num_vertices);
		for (int i = 0; i < num_vertices; ++i) {
			visited[i] = false;
		}
		queue<int> q;
		q.push(ver_index[v]);
		int index;
		while (q.empty() == false) {
			index = q.front();
			q.pop();
			cout << vertices[index] << " ";
			visited[index] = true;

			for (auto x : adj_list[index]) {
				if (visited[x.first] == false) {
					q.push(x.first);
				}
			}
		}
	}

	// 拓扑排序
	bool top_sort() {
		vector<int> in_degree(num_vertices, 0); // 记录节点的入度
		queue<int> q; // 记录入度为0的点
		// 统计节点的入度信息
		for (auto v : adj_list) {
			for (auto x : v) {
				++in_degree[x.first];
			}
		}
		// 统计入度为0的节点
		for (int i = 0; i < num_vertices; ++i) {
			if (in_degree[i] == 0) {
				q.push(i);
			}
		}
		// 输出拓扑序
		int index{ 0 };
		int cnt{ 0 }; // 记录位于拓扑序中的节点数量
		while (!q.empty()) {
			index = q.front();
			q.pop();
			++cnt;
			cout << vertices[index] << " ";
			// 将该节点的邻接点入度减一
			for (auto x : adj_list[index]) {
				--in_degree[x.first];
				if (in_degree[x.first] == 0) {
					q.push(x.first);
				}
			}
		}
		cout << std::endl;
		if (cnt != num_vertices) {
			return false;
		}
		return true;
	}
};