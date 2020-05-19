#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
using std::string;

class Graph {
protected:
	int num_vertices{ 0 }; // �ڵ�����
	std::vector<std::string> vertices; // �洢�ڵ�����
	std::map<std::string, int> ver_index; // �ɽڵ����ֵõ�����
	bool is_directed{ false }; // �Ƿ�����ͼ
public:
	// �޲ι��캯���������ͼ
	Graph(bool is_dir = false) : is_directed{ is_dir } {}
	// ����ڵ���Ϣ�����й���
	Graph(std::vector<std::string>& v, bool is_dir = false) : Graph(is_dir) {
		num_vertices = v.size();
		vertices = v;
		for (int i = 0; i < v.size(); ++i) {
			ver_index[v[i]] = i;
		}
	}
	// ����ڵ��������й���
	Graph(int num_v, bool is_dir = false) : Graph(is_dir) {
		num_vertices = num_v;
		vertices.resize(num_vertices);
		for (int i = 0; i < num_v; ++i) {
			vertices[i] = std::to_string(i);
			ver_index[vertices[i]] = i;
		}
	}
	virtual void print() = 0;
	// ����ڵ�
	virtual void insert_vertex() {
		insert_vertex(std::to_string(num_vertices));
	}
	virtual bool insert_vertex(string v) {
		if (ver_index.find(v) != ver_index.end()) {
			// �Ѿ�����ͬ���ڵ�
			return false;
		}
		vertices.push_back(v);
		ver_index[v] = num_vertices; // �ڵ��±��0��ʼ
		++num_vertices;
	}
	// ����ߣ������ڲ����µĽڵ�ı�
	virtual bool insert_edge(string v_begin, string v_end, int weight = 1) {
		/*
			v_begin: ��ʼ�ڵ�
			v_end: �����ڵ�
		*/
		// �����
		insert_vertex(v_begin);
		insert_vertex(v_end);
		return insert_edge(ver_index[v_begin], ver_index[v_end], weight);
	}
	// ����ߣ�ֻ�����ڲ������нڵ�ı�
	virtual bool insert_edge(int src, int dst, int weight = 1) = 0;
};
