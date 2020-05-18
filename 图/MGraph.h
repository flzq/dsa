#pragma once
#include <vector>
#include <iostream>
#include "Graph.h"
using std::cout;

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
};
