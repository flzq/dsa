#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
using std::string;

class Graph {
protected:
	int num_vertices{ 0 }; // 节点数量
	std::vector<std::string> vertices; // 存储节点名字
	std::map<std::string, int> ver_index; // 由节点名字得到索引
	std::vector<bool> visited;
	bool is_directed{ false }; // 是否有向图
	// 深度优先搜索
	// virtual void dfs(int v) = 0;
public:
	// 无参构造函数，构造空图
	Graph(bool is_dir = false) : is_directed{ is_dir } {}
	// 传入节点信息，进行构造
	Graph(std::vector<std::string>& v, bool is_dir = false) : Graph(is_dir) {
		num_vertices = v.size();
		vertices = v;
		for (int i = 0; i < v.size(); ++i) {
			ver_index[v[i]] = i;
		}
	}
	// 传入节点数，进行构造
	Graph(int num_v, bool is_dir = false) : Graph(is_dir) {
		num_vertices = num_v;
		vertices.resize(num_vertices);
		for (int i = 0; i < num_v; ++i) {
			vertices[i] = std::to_string(i);
			ver_index[vertices[i]] = i;
		}
	}
	virtual void print() = 0;
	// 插入节点
	virtual void insert_vertex() {
		insert_vertex(std::to_string(num_vertices));
	}
	virtual bool insert_vertex(string v) {
		if (ver_index.find(v) != ver_index.end()) {
			// 已经存在同名节点
			return false;
		}
		vertices.push_back(v);
		ver_index[v] = num_vertices; // 节点下标从0开始
		++num_vertices;
	}
	// 插入边，可用于插入新的节点的边
	virtual bool insert_edge(string v_begin, string v_end, int weight = 1) {
		/*
			v_begin: 开始节点
			v_end: 结束节点
		*/
		// 插入点
		insert_vertex(v_begin);
		insert_vertex(v_end);
		return insert_edge(ver_index[v_begin], ver_index[v_end], weight);
	}
	// 插入边，只可用于插入已有节点的边
	virtual bool insert_edge(int src, int dst, int weight = 1) = 0;
	// 删除边
	virtual bool remove_edge(string src, string dst) {
		// 有一个节点不存在，则删除失败
		if (ver_index.find(src) == ver_index.end() || ver_index.find(dst) == ver_index.end()) {
			return false;
		}
		return remove_edge(ver_index[src], ver_index[dst]);
	}
	virtual bool remove_edge(int src, int dst) = 0;

	// 查找边
	virtual bool find_edge(string src, string dst) {
		// 不存在节点，则查找不到
		if (ver_index.find(src) == ver_index.end() || ver_index.find(dst) == ver_index.end()) {
			return false;
		}
		return find_edge(ver_index[src], ver_index[dst]);
	}
	virtual bool find_edge(int src, int dst) = 0;

	// 深度优先搜索
	//virtual void dfs(string v) {
	//	if (ver_index.find(v) == ver_index.end()) {
	//		return;
	//	}
	//	visited.resize(num_vertices);
	//	for (int i = 0; i < num_vertices; ++i) {
	//		visited[i] = false;
	//	}
	//	dfs(ver_index[v]);
	//}
};
