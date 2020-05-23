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

	// �����������
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

	// ��������
	bool top_sort() {
		vector<int> in_degree(num_vertices, 0); // ��¼�ڵ�����
		queue<int> q; // ��¼���Ϊ0�ĵ�
		// ͳ�ƽڵ�������Ϣ
		for (int i = 0; i < num_vertices; ++i) {
			for (int j = 0; j < num_vertices; ++j) {
				if (matrix[i][j] != INT_MAX) {
					++in_degree[j];
				}
			}
		}
		// ͳ�����Ϊ0�Ľڵ�
		for (int i = 0; i < num_vertices; ++i) {
			if (in_degree[i] == 0) {
				q.push(i);
			}
		}
		// ���������
		int index;
		int cnt{ 0 }; // ͳ��������Ľڵ���
		while (!q.empty()) {
			index = q.front();
			q.pop();
			cout << vertices[index] << " ";
			++cnt;
			// �������
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

	// Dijkstra�㷨���㵥Դ���·���������и���
	void dijkstra(string str) {
		if (ver_index.find(str) == ver_index.end()) {
			return;
		}
		vector<int> from(num_vertices, -1); // ��¼Դ��
		vector<int> dis(num_vertices, INT_MAX); // ��¼����
		vector<bool> visited(num_vertices, false);
		dis[ver_index[str]] = 0;
		for (int i = 0; i < num_vertices; ++i) { // ÿ��ѭ��ȷ��һ���㣬һ��ѭ��num_vertices��
			// ѡ��δȷ�ϵĵ��о�����С�ĵ�
			int min_index = -1;
			int min_dis = INT_MAX;
			for (int j = 0; j < num_vertices; ++j) {
				if (!visited[j] && dis[j] < min_dis) {
					min_dis = dis[j];
					min_index = j;
				}
			}
			if (min_index == -1) {
				break; // �Ҳ���������С�ĵ㣬ͼ��ͨ��
			}
			// ������С�ĵ����ȷ���Ѿ��õ�����̾���
			visited[min_index] = true;
			// �Ӹõ�����������������ڵĵ�ľ���
			for (int w = 0; w < num_vertices; ++w) {
				if (matrix[min_index][w] != INT_MAX && dis[min_index] + matrix[min_index][w] < dis[w]) {
					dis[w] = dis[min_index] + matrix[min_index][w];
					from[w] = min_index;
				}
			}
		}

		// ��ӡ
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

	// ʹ�ö��У����㵥Դ���·���������и��ߣ������и���·
	void weighted_shortest_path(string str) {
		if (ver_index.find(str) == ver_index.end()) {
			return;
		}
		vector<int> dis(num_vertices, INT_MAX); // ����
		vector<int> from(num_vertices, -1); // Դ��
		queue<int> q; // ���м�¼����ı��˵Ľڵ���
		dis[ver_index[str]] = 0;
		q.push(ver_index[str]);
		int v;
		while (!q.empty()) {
			v = q.front();
			q.pop();
			// �鿴��vΪ�н�㵽�ڽӱߵľ����Ƿ���С��
			for (int w = 0; w < num_vertices; ++w) {
				if (matrix[v][w] != INT_MAX && dis[v] + matrix[v][w] < dis[w]) {
					from[w] = v;
					dis[w] = dis[v] + matrix[v][w];
					q.push(w);
				}
			}
		}
		// ��ӡ
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
