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
};