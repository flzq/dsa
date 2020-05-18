#pragma once
#include "BinTree.h"

template <typename T>
class BSTree : public BinTree<T> {
protected:
	// 递归插入
	BinNode<T>* _rinsert(BinNode<T>* r, T x);
	// 递归删除
	BinNode<T>* _rremove(BinNode<T>* r, T x);
	// 循环找到子树中最大节点
	BinNode<T>* _ifind_max(BinNode<T>* r);
public:
	BSTree();

	// 找到最大值
	BinNode<T>* find_max();
	// 找到最小值
	BinNode<T>* find_min();
	// 找到某一个值
	BinNode<T>* find(T x);


	// 插入节点
	bool insert(T x);

	// 删除节点
	bool remove(T x);
};

// 二叉搜索树删除
template <typename T>
bool BSTree<T>::remove(T x) {
	try {
		this->root = _rremove(this->root, x);
	}
	catch (const int& e) {
		return false;
	}
	return true;
}
template <typename T>
BinNode<T>* BSTree<T>::_rremove(BinNode<T>* r, T x) {
	if (r == nullptr) {
		throw - 1;
	}
	else if (x < r->data) {
		r->left = _rremove(r->left, x);
	}
	else if (r->data < x) {
		r->right = _rremove(r->right, x);
	}
	else {
		// 当前节点要删除
		// 用左子树最大值代替当前要删除的节点
		// 然后删除左子树中的最大值
		BinNode<T>* tmp{ nullptr };
		if (r->left && r->right) {
			tmp = _ifind_max(r->left);
			r->data = tmp->data;
			r->left = _rremove(r->left, tmp->data);
		}
		else {
			tmp = r;
			r = r->left ? r->left : r->right;
			delete tmp;
		}
	}
	return r;
}
// 循环找到子树中最大节点
template <typename T>
BinNode<T>* BSTree<T>::_ifind_max(BinNode<T>* r) {
	if (r == nullptr) {
		return nullptr;
	}
	while (r->right) {
		r = r->right;
	}
	return r;
}

// 二叉搜索树插入
template <typename T>
bool BSTree<T>::insert(T x) {
	try {
		this->root = _rinsert(this->root, x);
	}
	catch (const int& e) {
		// 捕获已经存在节点导致插入失败，
		// 或者内存分配失败导致插入失败
		return false;
	}
	return true;
}
// 递归插入
template <typename T>
BinNode<T>* BSTree<T>::_rinsert(BinNode<T>* r, T x) {
	if (r == nullptr) {
		r = new BinNode<T>{ x };
		if (r == nullptr) {
			// 内存分配失败
			throw - 1;
		}
	}
	else if (r->data == x) {
		// 已经存在x
		throw - 2;
	}
	else if (x < r->data) {
		r->left = _rinsert(r->left, x);
	}
	else if (r->data < x) {
		r->right = _rinsert(r->right, x);
	}

	return r;
}

template <typename T>
BSTree<T>::BSTree() {
	this->root = nullptr;
}
// 找到最大值
template <typename T>
BinNode<T>* BSTree<T>::find_max() {
	if (this->root == nullptr) {
		return nullptr;
	}
	BinNode<T>* r = this->root;
	while (r->right) {
		r = r->right;
	}

	return r;
}
// 找到最小值
template <typename T>
BinNode<T>* BSTree<T>::find_min() {
	if (this->root == nullptr) {
		return nullptr;
	}
	BinNode<T>* r = this->root;
	while (r->left) {
		r = r->left;
	}

	return r;
}
// 找到指定的某个值
template <typename T>
BinNode<T>* BSTree<T>::find(T x) {
	if (this->root == nullptr) {
		return nullptr;
	}
	BinNode<T>* r = this->root;
	while (r && (r->data != x)) {
		if (x < r->data) {
			r = r->left;
		}
		else {
			r = r->right;
		}
	}
	return r;
}
