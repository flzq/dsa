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
	vector<HuffmanTree> hts; // ���쵥�ڵ�Ĺ�������
	cin >> N;
	while (N--) {
		cin >> weight;
		hts.emplace_back(weight);
	}
	// ʹ�ù��������鹹���������
	HuffmanTree huffman{ hts };
	// ��ӡ��������
	huffman.print();
}