#pragma once
/*
AVL 树的实现
对树的旋转参考了：《大话数据结构》
但这里不使用平衡因子，而是在节点中加入了节点的高度
高度：从叶子节点到子树根节点（叶子节点高度为0），空树高度为-1
*/

#include <algorithm>
#include "BSTree.h"


template <typename T>
class AVLTree : public BSTree<T> {
private:
	// 递归插入节点
	BinNode<T>* _rinsert(BinNode<T>* r, T x);
	// 求子树高度
	int get_height(BinNode<T>* r);
	// 求平衡因子: balanced factor
	int get_bf(BinNode<T>* r);
	// 左旋
	BinNode<T>* L_rotation(BinNode<T>* r);
	// 右旋
	BinNode<T>* R_rotation(BinNode<T>* r);
public:
	bool insert(T x);
};

// AVL树的插入
template <typename T>
bool AVLTree<T>::insert(T x) {
	try {
		/*
			插入失败有两种情况：
				1. 节点内存分配失败；
				2. 已经存在该节点
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
			// 内存分配失败
			throw - 1;
		}
	}
	else if (x < r->data) { // 往左子树插入
		// 往左子树插入
		r->left = _rinsert(r->left, x);
		// 判断是否要重新平衡
		if (get_bf(r) == 2) { // 重新平衡
			// 判断子树根节点与左子树平衡因子是否同号
			if (get_bf(r->left) > 0) { // 同号，也就是往子树根节点左子树的左子树插入，要进行LL旋转，只需要进行一次根节点的右旋
				r = R_rotation(r);
			}
			else { // 异号，也就是往子树根节点左子树的右子树插入，要进行LR选择，先对左子树进行一次左旋，再对根节点进行一次右旋
				r->left = L_rotation(r->left);
				r = R_rotation(r);
			}

		}
	}
	else if (r->data < x) { // 往右子树插入
		r->right = _rinsert(r->right, x);
		// 判断是否要重新平衡
		if (get_bf(r) == -2) { // 重新平衡
			// 判断子树根节点与左子树平衡因子是否同号
			if (get_bf(r->right) < 0) { // 同号，也就是往子树根节点右子树的右子树插入，要进行RR旋转，只需要进行一次根节点的左旋
				r = L_rotation(r);
			}
			else { // 异号，也就是往子树根节点右子树的左子树插入，要进行RL选择，先对右子树进行一次右旋，再对根节点进行一次左旋
				r->right = R_rotation(r->right);
				r = L_rotation(r);
			}

		}
	}
	else {
		// 存在该节点
		throw - 2;
	}
	// 更新高度
	r->height = std::max(get_height(r->left), get_height(r->right)) + 1;

	return r;
}
// 左旋
template <typename T>
BinNode<T>* AVLTree<T>::L_rotation(BinNode<T>* r) {
	BinNode<T>* child = r->right;
	r->right = child->left;
	child->left = r;
	// 更新高度
	r->height = std::max(get_height(r->left), get_height(r->right)) + 1; // 根节点变化了，降低了，先更新高度
	child->height = std::max(get_height(child->left), get_height(child->right)) + 1; // 然后孩子节点升高了，再更新高度
	return child;
}
// 右旋
template <typename T>
BinNode<T>* AVLTree<T>::R_rotation(BinNode<T>* r) {
	BinNode<T>* child = r->left;
	r->left = child->right;
	child->right = r;
	// 更新高度
	r->height = std::max(get_height(r->left), get_height(r->right)) + 1;
	child->height = std::max(get_height(child->left), get_height(child->right)) + 1;
	return child;
}
// 求子树的高度
template <typename T>
int AVLTree<T>::get_height(BinNode<T>* r) {
	// 如果子树为空，高度为-1
	// 叶子节点高度为0
	if (r == nullptr) {
		return -1;
	}

	return r->height;
}
// 求平衡因子
template <typename T>
int AVLTree<T>::get_bf(BinNode<T>* r) {
	return (get_height(r->left) - get_height(r->right));
}

