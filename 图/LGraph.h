#pragma once
/*
	�ڽӱ��ʵ��
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
	vector<map<int, int>> adj_list; // �ڽӱ�
	// �����ڽӱ�
	void set_adjlist() {
		adj_list.resize(num_vertices);
		for (auto x : adj_list) {
			x.clear();
		}
	}

	// �����������
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
	// ����ڵ�
	void insert_vertex() {
		insert_vertex(std::to_string(num_vertices));
	}
	bool insert_vertex(string v) {
		bool tmp = Graph::insert_vertex(v);
		if (tmp == false) {
			return false;
		}
		// ���ڽӱ�����ӽڵ�
		adj_list.push_back(map<int, int>());
		return true;
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
		/*
			src: ��ʼ�ڵ���
			dst: �����ڵ���
		*/
		// ��ֱ�ӵ��øú������жϽڵ��Ƿ���ڣ�����ڵ㲻���ڣ����ܲ���
		if (src < 0 || src >= num_vertices || dst < 0 || dst >= num_vertices) {
			return false;
		}
		// �ж��Ƿ���ڱ�
		if (adj_list[src].find(dst) != adj_list[src].end()) {
			// ���Ѿ�����
			return false;
		}
		// �����
		adj_list[src].insert(std::pair<int, int>(dst, weight));
		if (is_directed == false) {
			adj_list[dst].insert(std::pair<int, int>(src, weight));
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
		if (adj_list[src].find(dst) == adj_list[src].end()) {
			return false;
		}
		adj_list[src].erase(dst);
		if (is_directed == false) {
			adj_list[dst].erase(src);
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
		// �����ڣ�����false
		if (adj_list[src].find(dst) == adj_list[src].end()) {
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

			for (auto x : adj_list[index]) {
				if (visited[x.first] == false) {
					q.push(x.first);
				}
			}
		}
	}

	// ��������
	bool top_sort() {
		vector<int> in_degree(num_vertices, 0); // ��¼�ڵ�����
		queue<int> q; // ��¼���Ϊ0�ĵ�
		// ͳ�ƽڵ�������Ϣ
		for (auto v : adj_list) {
			for (auto x : v) {
				++in_degree[x.first];
			}
		}
		// ͳ�����Ϊ0�Ľڵ�
		for (int i = 0; i < num_vertices; ++i) {
			if (in_degree[i] == 0) {
				q.push(i);
			}
		}
		// ���������
		int index{ 0 };
		int cnt{ 0 }; // ��¼λ���������еĽڵ�����
		while (!q.empty()) {
			index = q.front();
			q.pop();
			++cnt;
			cout << vertices[index] << " ";
			// ���ýڵ���ڽӵ���ȼ�һ
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