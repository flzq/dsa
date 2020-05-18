#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include "BinTree.h"
#include "BSTree.h"
#include "AVLTree.h"
#include "MiniHeap.h"
#include "DisjointSet.h"



// 测试二叉树类
void test_tree() {
	BinTree<int> bt{ 11 };
	bt.insert(11, 0, 22);
	bt.insert(11, 1, 33);
	bt.insert(33, 1, 55);
	bt.insert(33, 0, 44);
	bt.insert(22, 1, 77);
	bt.insert(22, 0, 66);
	std::cout << "pre trans" << std::endl;
	bt.rpre_trans();
	bt.ipre_trans();
	std::cout << "in trans" << std::endl;
	bt.rin_trans();
	bt.iin_trans();
	std::cout << "post trans" << std::endl;
	bt.rpost_trans();
	bt.ipost_trans();
	std::cout << "level trans" << std::endl;
	bt.level_trans();
	bt.rpre_print();
}

// 统计叶子节点数量
void count_leaves() {
	std::string name, s1, s2;
	std::cin >> name;
	BinTree<std::string> bt{ name };
	std::cin >> name;
	while (name != "-") {
		std::cin >> s1 >> s2;
		if (s1 != "-") {
			bt.insert(name, 0, s1);
		}
		if (s2 != "-") {
			bt.insert(name, 1, s2);
		}
		std::cin >> name;
	}
	std::cout << "Leaves counter: " << bt.count() << std::endl;
}

// 测试二叉搜索树
void test_bst() {
	BSTree<int> bst;
	/*
	       20
	   10        30
	     15    25   35
	*/
	bst.insert(20);
	bst.insert(30);
	bst.insert(10);
	bst.insert(15);
	bst.insert(25);
	bst.insert(35);
	bst.rpre_print();
	std::cout << "-------------" << std::endl;
	bst.remove(30);
	bst.rpre_print();
}

// 测试平衡二叉树
void test_avl() {
	AVLTree<int> avl;
	avl.insert(20);
	avl.insert(10);
	avl.insert(30);
	avl.rpre_print();
	std::cout << "-----------" << std::endl;
	avl.insert(25);
	avl.insert(27);
	avl.rpre_print();
}

// 测试堆
void test_heap() {
	// MiniHeap<int> heap{ 100 };
	/*  10 20 30  5 6
	         5
		6      30
	  20  10
	*/
	/*heap.insert(10);
	heap.print();
	heap.insert(20);
	heap.insert(30);
	heap.print();
	heap.insert(5);
	heap.print();
	heap.insert(6);
	heap.print();
	int x;
	heap.remove(x);
	std::cout << x << std::endl;
	heap.print();*/

	/*int a[6]{ 5, 8, 0, 10, 4, 9 };
	MiniHeap<int> heap{ a, 6, 50 };
	heap.print();*/

	// 使用编译器提供的优先队列
	/*std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	q.push(445);
	q.push(222);
	q.push(333);
	q.push(634);
	q.push(23);
	std::cout << q.top() << std::endl;
	q.pop();*/
}

// 测试并查集
void test_disjointset() {
	DisjointSet<int> ds{ 10 };
	ds.insert(11);
	ds.insert(22);
	ds.insert(66);
	ds.insert(-5);
	ds.insert(124);
	ds.union_set(11, 66);
	ds.union_set(11, 22);
	ds.union_set(124, -5);
	ds.union_set(124, 11);
	ds.print();
	ds.find(124);
	putchar('\n');
	ds.print();
}

int main() {
	// 测试二叉树类
	// test_tree()
	// 统计叶子节点数量
	// count_leaves();
	// 测试二叉搜索树
	// test_bst();
	// test_avl();
	// test_heap();
	//std::set<int> s;
	//s.insert(11);
	//s.insert(22);
	//s.insert(5);
	//for (auto x : s) {
	//	std::cout << x << std::endl;
	//}
	test_disjointset();

	return 0;
}