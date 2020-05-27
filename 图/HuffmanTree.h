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
		// ʹ��С����
		priority_queue<HuffmanTree> pq(vht.begin(), vht.end()); // ʹ�ù��������鹹��С����
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
	// �ݹ��ӡ
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
	bool operator<(const HuffmanTree& ht) const { // ���ڹ���С����
		return root->data > ht.root->data;
	}
};
