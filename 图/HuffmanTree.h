#pragma once
#include <queue>
#include <iostream>
#include <vector>
using std::vector;
using std::priority_queue;
using std::cout;
using std::endl;
void huffman_tree();

struct Node {
	int data;
	Node* left{ nullptr };
	Node* right{ nullptr };
	Node() : left{ nullptr }, right{ nullptr } {}
	Node(int weight) : Node() {
		data = weight;
	}

};

struct HuffmanTree {
	Node* root{ nullptr };
	HuffmanTree() : root{ nullptr } {}
	HuffmanTree(int weight) {
		root = new Node{ weight };
	}
	HuffmanTree(vector<HuffmanTree>& vht) {
		// 使用小顶堆
		priority_queue<HuffmanTree> pq(vht.begin(), vht.end()); // 使用哈夫曼数组构建小顶堆
		HuffmanTree tmp;
		while (pq.size() != 1) {
			tmp.root = new Node();
			tmp.root->left = pq.top().root;
			pq.pop();
			tmp.root->right = pq.top().root;
			pq.pop();
			tmp.root->data = tmp.root->left->data + tmp.root->right->data;
			pq.push(tmp);
		}
		root = pq.top().root;
	}
	void print() {
		_rprint(root, 0);
	}
	// 递归打印
	void _rprint(Node* r, int depth) {
		for (int i = 0; i < depth; ++i) {
			cout << " ";
		}
		if (r == nullptr) {
			cout << "[/]" << endl;
		}
		else {
			cout << r->data << endl;
			_rprint(r->left, depth + 1);
			_rprint(r->right, depth + 1);
		}
	}
	bool operator<(const HuffmanTree& ht) const { // 用于构造小顶堆
		return root->data > ht.root->data;
	}
};
