#pragma once
#include "BinTree.h"

template <typename T>
class BSTree : public BinTree<T> {
protected:
	// �ݹ����
	BinNode<T>* _rinsert(BinNode<T>* r, T x);
	// �ݹ�ɾ��
	BinNode<T>* _rremove(BinNode<T>* r, T x);
	// ѭ���ҵ����������ڵ�
	BinNode<T>* _ifind_max(BinNode<T>* r);
public:
	BSTree();

	// �ҵ����ֵ
	BinNode<T>* find_max();
	// �ҵ���Сֵ
	BinNode<T>* find_min();
	// �ҵ�ĳһ��ֵ
	BinNode<T>* find(T x);


	// ����ڵ�
	bool insert(T x);

	// ɾ���ڵ�
	bool remove(T x);
};

// ����������ɾ��
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
		// ��ǰ�ڵ�Ҫɾ��
		// �����������ֵ���浱ǰҪɾ���Ľڵ�
		// Ȼ��ɾ���������е����ֵ
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
// ѭ���ҵ����������ڵ�
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

// ��������������
template <typename T>
bool BSTree<T>::insert(T x) {
	try {
		this->root = _rinsert(this->root, x);
	}
	catch (const int& e) {
		// �����Ѿ����ڽڵ㵼�²���ʧ�ܣ�
		// �����ڴ����ʧ�ܵ��²���ʧ��
		return false;
	}
	return true;
}
// �ݹ����
template <typename T>
BinNode<T>* BSTree<T>::_rinsert(BinNode<T>* r, T x) {
	if (r == nullptr) {
		r = new BinNode<T>{ x };
		if (r == nullptr) {
			// �ڴ����ʧ��
			throw - 1;
		}
	}
	else if (r->data == x) {
		// �Ѿ�����x
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
// �ҵ����ֵ
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
// �ҵ���Сֵ
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
// �ҵ�ָ����ĳ��ֵ
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
