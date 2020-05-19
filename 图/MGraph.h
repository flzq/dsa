#pragma once
#include <vector>
#include <iostream>
#include "Graph.h"
using std::cout;

class MGraph : Graph {
protected:
	std::vector<std::vector<int>> matrix; // �ڽӾ���
	// ���ڹ��캯���й����ڽӾ���
	void set_matrix() {
		matrix.resize(num_vertices);
		for (int i = 0; i < num_vertices; ++i) {
			matrix[i].resize(num_vertices);
			for (int j = 0; j < num_vertices; ++j) {
				matrix[i][j] = INT_MAX; // �ü���ֵ��ʾû����ͬ
			}
		}
	}

	// �����������
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
	// ����ڵ�
	void insert_vertex() {
		insert_vertex(std::to_string(num_vertices));
	}
	bool insert_vertex(string v) {
		bool tmp = Graph::insert_vertex(v);
		if (!tmp) {
			return false;
		}

		// ���ڽӾ�������ӽڵ�
		// ����ԭ���ľ����������
		for (int i = 0; i < num_vertices - 1; ++i) {
			matrix[i].push_back(INT_MAX);
		}
		// ������һ��
		matrix.push_back(std::vector<int>(num_vertices, INT_MAX));
	}
	// �����
	bool insert_edge(string v_begin, string v_end, int weight = 1) {
		/*
			v_begin: ��ʼ�ڵ�
			v_end: �����ڵ�
		*/
		return Graph::insert_edge(v_begin, v_end, weight); // ��Graph�л����bool insert_edge(int src, int dst, int weight = 1)
	}
	// ͨ���ڵ��Ų���ߣ�ֻ�����ڲ������нڵ�ı�
	bool insert_edge(int src, int dst, int weight = 1) {
		// ��ֱ�ӵ��øú������жϽڵ��Ƿ���ڣ�����ڵ㲻���ڣ����ܲ���
		if (src < 0 || src >= num_vertices || dst < 0 || dst >= num_vertices) {
			return false;
		}
		// �ж��Ƿ���ڱ�
		if (matrix[src][dst] != INT_MAX) {
			// ���Ѿ�����
			return false;
		}
		matrix[src][dst] = weight;
		if (is_directed == false) {
			matrix[dst][src] = weight;
		}
		return true;
	}
	// ɾ����
	virtual bool remove_edge(string src, string dst) {
		return Graph::remove_edge(src, dst);
	}
	virtual bool remove_edge(int src, int dst) {
		// ��ֱ�ӵ��øú������жϽڵ��Ƿ���ڣ�����ڵ㲻���ڣ�����ɾ��
		if (src < 0 || src >= num_vertices || dst < 0 || dst >= num_vertices) {
			return false;
		}
		// ���û�бߣ�����ɾ��
		if (matrix[src][dst] == INT_MAX) {
			return false;
		}
		matrix[src][dst] = INT_MAX;
		if (is_directed == false) {
			matrix[dst][src] = INT_MAX;
		}
		return true;
	}

	// ���ұ�
	virtual bool find_edge(string src, string dst) {
		return Graph::find_edge(src, dst);
	}
	virtual bool find_edge(int src, int dst) {
		// ��ֱ�ӵ��øú������жϽڵ��Ƿ���ڣ�����ڵ㲻���ڣ����޷�����
		if (src < 0 || src >= num_vertices || dst < 0 || dst >= num_vertices) {
			return false;
		}
		// �жϱ��Ƿ����
		if (matrix[src][dst] == INT_MAX) {
			return false;
		}
		return true;
	}

	// �����������
	virtual void dfs(string v) {
		Graph::dfs(v);
	}
};
