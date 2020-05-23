#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include "Graph.h"
using std::cout;
using std::queue;
using std::vector;
using std::endl;
using std::queue;

class MGraph : Graph {
protected:
	std::vector<std::vector<int>> matrix; // 邻接矩阵
	// 用于构造函数中构造邻接矩阵
	void set_matrix() {
		matrix.resize(num_vertices);
		for (int i = 0; i < num_vertices; ++i) {
			matrix[i].resize(num_vertices);
			for (int j = 0; j < num_vertices; ++j) {
				matrix[i][j] = INT_MAX; // 用极大值表示没有连同
			}
		}
	}

	// 深度优先搜索
	virtual void dfs(int v) {
		cout << vertices[v] << " ";
		visited[v] = true;
		for (int i = 0; i < num_vertices; ++i) {
			if (visited[i] == false && matrix[v][i] != INT_MAX) {
				dfs(i);
			}
		}
	}

public:
	MGraph(bool is_dir = false) : Graph(is_dir) {}
	MGraph(std::vector<std::string>& v, bool is_dir = false) : Graph(v, is_dir) {
		set_matrix();
	}
	MGraph(int n, bool is_dir = false) : Graph(n, is_dir) {
		set_matrix();
	}
	void print() {
		cout << '\t';
		for (int i = 0; i < num_vertices; ++i) {
			cout << vertices[i] << '\t';
		}
		cout << std::endl;
		for (int i = 0; i < num_vertices; ++i) {
			cout << vertices[i] << '\t';
			for (int j = 0; j < num_vertices; ++j) {
				if (matrix[i][j] == INT_MAX) {
					cout << "-" << '\t';
				}
				else {
					cout << matrix[i][j] << '\t';
				}
			}
			cout << std::endl;
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
		if (!tmp) {
			return false;
		}

		// 往邻接矩阵中添加节点
		// 先在原来的矩阵中添加列
		for (int i = 0; i < num_vertices - 1; ++i) {
			matrix[i].push_back(INT_MAX);
		}
		// 再增加一行
		matrix.push_back(std::vector<int>(num_vertices, INT_MAX));
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
		// 若直接调用该函数，判断节点是否存在，如果节点不存在，则不能插入
		if (src < 0 || src >= num_vertices || dst < 0 || dst >= num_vertices) {
			return false;
		}
		// 判断是否存在边
		if (matrix[src][dst] != INT_MAX) {
			// 边已经存在
			return false;
		}
		matrix[src][dst] = weight;
		if (is_directed == false) {
			matrix[dst][src] = weight;
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
		if (matrix[src][dst] == INT_MAX) {
			return false;
		}
		matrix[src][dst] = INT_MAX;
		if (is_directed == false) {
			matrix[dst][src] = INT_MAX;
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
		if (matrix[src][dst] == INT_MAX) {
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

			for (int i = 0; i < num_vertices; ++i) {
				if (visited[i] == false && matrix[index][i] != INT_MAX) {
					q.push(i);
				}
			}
		}
	}

	// 拓扑排序
	bool top_sort() {
		vector<int> in_degree(num_vertices, 0); // 记录节点的入度
		queue<int> q; // 记录入度为0的点
		// 统计节点的入度信息
		for (int i = 0; i < num_vertices; ++i) {
			for (int j = 0; j < num_vertices; ++j) {
				if (matrix[i][j] != INT_MAX) {
					++in_degree[j];
				}
			}
		}
		// 统计入度为0的节点
		for (int i = 0; i < num_vertices; ++i) {
			if (in_degree[i] == 0) {
				q.push(i);
			}
		}
		// 输出拓扑序
		int index;
		int cnt{ 0 }; // 统计拓扑序的节点数
		while (!q.empty()) {
			index = q.front();
			q.pop();
			cout << vertices[index] << " ";
			++cnt;
			// 更新入度
			for (int i = 0; i < num_vertices; ++i) {
				if (matrix[index][i] != INT_MAX) {
					--in_degree[i];
					if (in_degree[i] == 0) {
						q.push(i);
					}
				}
			}
		}
		cout << std::endl;
		if (cnt != num_vertices) {
			return false;
		}
		return true;
	}

	// Dijkstra算法计算单源最短路径，不能有负边
	void dijkstra(string str) {
		if (ver_index.find(str) == ver_index.end()) {
			return;
		}
		vector<int> from(num_vertices, -1); // 记录源点
		vector<int> dis(num_vertices, INT_MAX); // 记录距离
		vector<bool> visited(num_vertices, false);
		dis[ver_index[str]] = 0;
		for (int i = 0; i < num_vertices; ++i) { // 每次循环确定一个点，一共循环num_vertices次
			// 选择未确认的点中距离最小的点
			int min_index = -1;
			int min_dis = INT_MAX;
			for (int j = 0; j < num_vertices; ++j) {
				if (!visited[j] && dis[j] < min_dis) {
					min_dis = dis[j];
					min_index = j;
				}
			}
			if (min_index == -1) {
				break; // 找不到距离最小的点，图不通了
			}
			// 距离最小的点可以确认已经得到了最短距离
			visited[min_index] = true;
			// 从该点出发，更新与他相邻的点的距离
			for (int w = 0; w < num_vertices; ++w) {
				if (matrix[min_index][w] != INT_MAX && dis[min_index] + matrix[min_index][w] < dis[w]) {
					dis[w] = dis[min_index] + matrix[min_index][w];
					from[w] = min_index;
				}
			}
		}

		// 打印
		for (int i = 0; i < num_vertices; ++i) {
			cout << i << "\t";
		}
		cout << endl;
		for (int i = 0; i < num_vertices; ++i) {
			cout << vertices[i] << "\t";
		}
		cout << endl;
		for (int i = 0; i < num_vertices; ++i) {
			cout << dis[i] << "\t";
		}
		cout << endl;
		for (int i = 0; i < num_vertices; ++i) {
			cout << (from[i] == -1 ? "-" : vertices[from[i]]) << "\t";
		}
		cout << endl;
	}

	// 使用队列，计算单源最短路径，可以有负边，不能有负回路
	void weighted_shortest_path(string str) {
		if (ver_index.find(str) == ver_index.end()) {
			return;
		}
		vector<int> dis(num_vertices, INT_MAX); // 距离
		vector<int> from(num_vertices, -1); // 源点
		queue<int> q; // 队列记录距离改变了的节点编号
		dis[ver_index[str]] = 0;
		q.push(ver_index[str]);
		int v;
		while (!q.empty()) {
			v = q.front();
			q.pop();
			// 查看以v为中介点到邻接边的距离是否缩小了
			for (int w = 0; w < num_vertices; ++w) {
				if (matrix[v][w] != INT_MAX && dis[v] + matrix[v][w] < dis[w]) {
					from[w] = v;
					dis[w] = dis[v] + matrix[v][w];
					q.push(w);
				}
			}
		}
		// 打印
		for (int i = 0; i < num_vertices; ++i) {
			cout << i << "\t";
		}
		cout << endl;
		for (int i = 0; i < num_vertices; ++i) {
			cout << vertices[i] << "\t";
		}
		cout << endl;
		for (int i = 0; i < num_vertices; ++i) {
			cout << dis[i] << "\t";
		}
		cout << endl;
		for (int i = 0; i < num_vertices; ++i) {
			cout << (from[i] == -1 ? "-" : vertices[from[i]]) << "\t";
		}
		cout << endl;
	}


};
