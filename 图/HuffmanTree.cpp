#include <iostream>
#include <vector>
#include "HuffmanTree.h"
using std::vector;
using std::cin;

/*
7
10 15 12 3 4 13 1
*/

void huffman_tree() {
	int N, weight;
	vector<HuffmanTree> hts; // 构造单节点的哈夫曼树
	cin >> N;
	while (N--) {
		cin >> weight;
		hts.emplace_back(weight);
	}
	// 使用哈夫曼数组构造哈夫曼树
	HuffmanTree huffman{ hts };
	// 打印哈夫曼树
	huffman.print();
}