#pragma once
/*
AVL ����ʵ��
��������ת�ο��ˣ��������ݽṹ��
�����ﲻʹ��ƽ�����ӣ������ڽڵ��м����˽ڵ�ĸ߶�
�߶ȣ���Ҷ�ӽڵ㵽�������ڵ㣨Ҷ�ӽڵ�߶�Ϊ0���������߶�Ϊ-1
*/

#include <algorithm>
#include "BSTree.h"


template <typename T>
class AVLTree : public BSTree<T> {
private:
	// �ݹ����ڵ�
	BinNode<T>* _rinsert(BinNode<T>* r, T x);
	// �������߶�
	int get_height(BinNode<T>* r);
	// ��ƽ������: balanced factor
	int get_bf(BinNode<T>* r);
	// ����
	BinNode<T>* L_rotation(BinNode<T>* r);
	// ����
	BinNode<T>* R_rotation(BinNode<T>* r);
public:
	bool insert(T x);
};

// AVL���Ĳ���
template <typename T>
bool AVLTree<T>::insert(T x) {
	try {
		/*
			����ʧ�������������
				1. �ڵ��ڴ����ʧ�ܣ�
				2. �Ѿ����ڸýڵ�
		*/
		this->root = _rinsert(this->root, x);
	}
	catch (const int& e) {
		std::cout << "insert error: " << e << std::endl;
		return false;
	}
	return true;
}
template <typename T>
BinNode<T>* AVLTree<T>::_rinsert(BinNode<T>* r, T x) {
	if (r == nullptr) {
		r = new BinNode<T>{ x };
		if (r == nullptr) {
			// �ڴ����ʧ��
			throw - 1;
		}
	}
	else if (x < r->data) { // ������������
		// ������������
		r->left = _rinsert(r->left, x);
		// �ж��Ƿ�Ҫ����ƽ��
		if (get_bf(r) == 2) { // ����ƽ��
			// �ж��������ڵ���������ƽ�������Ƿ�ͬ��
			if (get_bf(r->left) > 0) { // ͬ�ţ�Ҳ�������������ڵ������������������룬Ҫ����LL��ת��ֻ��Ҫ����һ�θ��ڵ������
				r = R_rotation(r);
			}
			else { // ��ţ�Ҳ�������������ڵ������������������룬Ҫ����LRѡ���ȶ�����������һ���������ٶԸ��ڵ����һ������
				r->left = L_rotation(r->left);
				r = R_rotation(r);
			}

		}
	}
	else if (r->data < x) { // ������������
		r->right = _rinsert(r->right, x);
		// �ж��Ƿ�Ҫ����ƽ��
		if (get_bf(r) == -2) { // ����ƽ��
			// �ж��������ڵ���������ƽ�������Ƿ�ͬ��
			if (get_bf(r->right) < 0) { // ͬ�ţ�Ҳ�������������ڵ������������������룬Ҫ����RR��ת��ֻ��Ҫ����һ�θ��ڵ������
				r = L_rotation(r);
			}
			else { // ��ţ�Ҳ�������������ڵ������������������룬Ҫ����RLѡ���ȶ�����������һ���������ٶԸ��ڵ����һ������
				r->right = R_rotation(r->right);
				r = L_rotation(r);
			}

		}
	}
	else {
		// ���ڸýڵ�
		throw - 2;
	}
	// ���¸߶�
	r->height = std::max(get_height(r->left), get_height(r->right)) + 1;

	return r;
}
// ����
template <typename T>
BinNode<T>* AVLTree<T>::L_rotation(BinNode<T>* r) {
	BinNode<T>* child = r->right;
	r->right = child->left;
	child->left = r;
	// ���¸߶�
	r->height = std::max(get_height(r->left), get_height(r->right)) + 1; // ���ڵ�仯�ˣ������ˣ��ȸ��¸߶�
	child->height = std::max(get_height(child->left), get_height(child->right)) + 1; // Ȼ���ӽڵ������ˣ��ٸ��¸߶�
	return child;
}
// ����
template <typename T>
BinNode<T>* AVLTree<T>::R_rotation(BinNode<T>* r) {
	BinNode<T>* child = r->left;
	r->left = child->right;
	child->right = r;
	// ���¸߶�
	r->height = std::max(get_height(r->left), get_height(r->right)) + 1;
	child->height = std::max(get_height(child->left), get_height(child->right)) + 1;
	return child;
}
// �������ĸ߶�
template <typename T>
int AVLTree<T>::get_height(BinNode<T>* r) {
	// �������Ϊ�գ��߶�Ϊ-1
	// Ҷ�ӽڵ�߶�Ϊ0
	if (r == nullptr) {
		return -1;
	}

	return r->height;
}
// ��ƽ������
template <typename T>
int AVLTree<T>::get_bf(BinNode<T>* r) {
	return (get_height(r->left) - get_height(r->right));
}

