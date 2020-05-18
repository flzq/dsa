#pragma once

#include <iostream>
#include <stack>
#include <queue>

template <typename T>
struct BinNode {
	T data;
	int height; // 记录树的高度，用于AVL树中
	BinNode<T>* left{ nullptr };
	BinNode<T>* right{ nullptr };
	BinNode(T x) : data{ x }, height{ 0 } {	}
};

template <typename T>
class BinTree
{
protected:
	BinNode<T>* root{ nullptr };

	void _rpre_trans(BinNode<T>* r);
	void _rin_trans(BinNode<T>* r);
	void _rpost_trans(BinNode<T>* r);
	BinNode<T>* _rfind(BinNode<T>* r, T x);
	void _rpre_print(BinNode<T>* r, int depth);

public:
	BinTree();
	BinTree(T x);
	~BinTree();

	// 递归先序遍历，打印二叉树
	void rpre_trans();
	// 递归中序遍历，打印二叉树
	void rin_trans();
	// 递归后续遍历，打印二叉树
	void rpost_trans();

	// 迭代先序遍历
	void ipre_trans();
	// 迭代中序遍历
	void iin_trans();
	// 迭代后续遍历
	void ipost_trans();

	// 层序遍历
	void level_trans();

	// 插入
	bool insert(T x, int pos, T y);
	// 递归先序遍历打印二叉树的结构
	void rpre_print();

	// 统计叶子节点数量
	int count();


};



// 统计叶子节点数量
template <typename T>
int BinTree<T>::count() {
	// 采用层序遍历统计叶子节点数量
	int counter{ 0 };
	if (root == nullptr) {
		return counter;
	}
	BinNode<T>* r = root;
	std::queue<BinNode<T>*> q;
	q.push(r);
	while (!q.empty()) {
		r = q.front();
		q.pop();
		if (r->left==nullptr && r->right==nullptr) {
			++counter;
		}
		else {
			if (r->left) {
				q.push(r->left);
			}
			if (r->right) {
				q.push(r->right);
			}
		}

	}

	return counter;
}

// 层序遍历
template <typename T>
void BinTree<T>::level_trans() {
	if (root == nullptr) {
		return;
	}
	BinNode<T>* r = root;
	std::queue<BinNode<T>*> q;
	q.push(r);
	while (!q.empty()) {
		r = q.front();
		q.pop();
		// 访问
		std::cout << r->data << " ";
		// 入队最有节点
		if (r->left) {
			q.push(r->left);
		}
		if (r->right) {
			q.push(r->right);
		}
	}
	std::cout << std::endl;
}

// 迭代先序遍历，打印二叉树
template <typename T>
void BinTree<T>::ipre_trans() {
	BinNode<T>* r = root;
	if (r == nullptr) {
		return;
	}

	std::stack<BinNode<T>*> st;
	while (r) {
		// 访问根节点，根节点入栈保存回路信息
		std::cout << r->data << " ";
		st.push(r);
		// 访问左子树
		r = r->left;

		// 判断左子树是否为空；且有根节点，为空则判断是否存在右子树
		while (r == nullptr && !st.empty()) {
			// 左子树为空，且栈中有值
			r = st.top();
			st.pop();
			// 转向右子树
			r = r->right;
		}
	}
	std::cout << std::endl;
}
// 迭代中序遍历
template <typename T>
void BinTree<T>::iin_trans() {
	BinNode<T>* r = root;
	if (root == nullptr) {
		return;
	}

	std::stack<BinNode<T>*> st;
	while (r) {
		// 中序遍历，遇到节点则入栈，出栈再访问
		st.push(r);

		// 转向左子树
		r = r->left;

		// 判断是否有左子树；
		// 无左子树，判断栈是否为空；
		// 无左子树，且不为空，则出栈子树根节点，访问根节点，再转向右子树
		while (r == nullptr && !st.empty()) {
			r = st.top();
			st.pop();
			// 出栈则访问子树根节点
			std::cout << r->data << " ";
			// 转向右子树
			r = r->right;
		}
	}
	std::cout << std::endl;
}
// 迭代后续遍历
// 信息节点：用于记录循环后续遍历中，节点入栈的次数，以及栈节点的地址
template <typename T>
struct IBinNode {
	BinNode<T>* root{ nullptr };
	int count{ 0 }; // 记录节点入栈的次数
	IBinNode(BinNode<T>* root_, int count_) : root{ root_ }, count{ count_ } {}
};
template <typename T>
void BinTree<T>::ipost_trans() {
	// 后序遍历，节点第二次出栈再访问
	BinNode<T>* r = root;
	if (r == nullptr) {
		return;
	}

	IBinNode<T>* tmp_ir{ nullptr }; // 用于暂存出栈的信息节点
	// 栈用于计算节点入栈的次数，以及节点地址
	std::stack<IBinNode<T>> st;
	while (r) {
		// 遇到节点先第一次入栈
		st.push(IBinNode<T>{r, 1});
		//st.push(r);
		//st_count.push(1); // 记录该节点第一次入栈

		// 转向左子树
		r = r->left;
		// 判断是否有左子树
		// 无左子树，判断栈是否为空
		// 无左子树，栈不为空，则子树根节点出栈
		// 判断第几次出栈，若为第一次出栈，则访问右子树，根节点第二次入栈
		// 然后子树根节点第二次入栈，转向右子树
		while (r == nullptr && !st.empty()) {
			// 子树根节点出栈
			tmp_ir = &(st.top());
			st.pop();
			// 判断出栈的节点入栈几次了
			if (tmp_ir->count == 1) {
				// 如果入栈一次，那么这就是第一次出栈
				// 转向右子树，然后第二次入栈
				r = tmp_ir->root->right;
				// 第二次入栈
				st.push(IBinNode<T>{tmp_ir->root, 2});
			}
			else {
				// 如果显示已经入栈两次，那么这次就是第二次出栈
				// 第二次出栈则直接访问
				std::cout << tmp_ir->root->data << " ";
				// 访问完该节点后，表示以该节点为根节点的子树已经访问完了，要回到该节点的父节点，因此回到while循环，这时r==nullptr，判断栈是否不为空，
				// 若为空，则表示访问完了，r = nullptr且st为空
				// 不空，然后继续出栈，得到这次出栈是已经访问节点的父节点，是第一次出栈，然后该节点入栈，转向右子树
			}

		}
	}

	std::cout << std::endl;
}

// 递归后续遍历，打印二叉树
template <typename T>
void BinTree<T>::rpost_trans() {
	_rpost_trans(root);
	std::cout << std::endl;
}
template <typename T>
void BinTree<T>::_rpost_trans(BinNode<T>* r) {
	if (r == nullptr) {
		return;
	}
	_rpost_trans(r->left);
	_rpost_trans(r->right);
	std::cout << r->data << " ";
}

// 递归中序遍历，打印二叉树
template <typename T>
void BinTree<T>::rin_trans() {
	_rin_trans(root);
	std::cout << std::endl;
}
template <typename T>
void BinTree<T>::_rin_trans(BinNode<T>* r) {
	if (r == nullptr) {
		return;
	}
	_rin_trans(r->left);
	std::cout << r->data << " ";
	_rin_trans(r->right);
}


template <typename T>
BinTree<T>::~BinTree() {
	// 采用层序遍历释放节点
	if (root == nullptr) {
		return;
	}
	std::queue<BinNode<T>*> q;
	q.push(root);
	while (!q.empty()) {
		root = q.front();
		q.pop();
		if (root->left) {
			q.push(root->left);
		}
		if (root->right) {
			q.push(root->right);
		}
		delete root;
	}
}

template <typename T>
BinTree<T>::BinTree() : root{ nullptr } {

}
template <typename T>
BinTree<T>::BinTree(T x) {
	root = new BinNode<T>{ x };
}

// 先序遍历，打印二叉树
template <typename T>
void BinTree<T>::rpre_trans() {
	_rpre_trans(root);
	std::cout << std::endl;
}
// 递归先序遍历，打印二叉树
template <typename T>
void BinTree<T>::_rpre_trans(BinNode<T>* r) {
	if (r == nullptr) {
		return;
	}
	std::cout << r->data << " ";
	_rpre_trans(r->left);
	_rpre_trans(r->right);
}

// 插入
template <typename T>
bool BinTree<T>::insert(T x, int pos, T y) {
	// x：要插入的父节点的值
	// pos：要插入的位置，0：左子树  1：右子树
	// y：要插入的值
	BinNode<T>* tmp = _rfind(root, x);
	if (tmp == nullptr) {
		return false;
	}
	if (pos == 0) {
		// 作为左孩子节点
		if (tmp->left == nullptr) {
			tmp->left = new BinNode<T>{ y };
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (tmp->right == nullptr) {
			tmp->right = new BinNode<T>{ y };
			return true;
		}
		else {
			return false;
		}
	}
}

// 递归查找值为x的地址
template <typename T>
BinNode<T>* BinTree<T>::_rfind(BinNode<T>* r, T x) {
	if (r == nullptr) {
		return nullptr;
	}

	if (r->data == x) {
		return r;
	}

	BinNode<T>* found = _rfind(r->left, x);

	return (found ? found : _rfind(r->right, x));


}

// 先序遍历打印二叉树的结构
template <typename T>
void BinTree<T>::rpre_print() {
	_rpre_print(root, 0);
}
// 递归前序打印二叉树的结构
template <typename T>
void BinTree<T>::_rpre_print(BinNode<T>* r, int depth) {
	for (int i = 0; i < depth; ++i) {
		std::cout << "  ";
	}
	if (r == nullptr) {
		std::cout << "[\\]" << std::endl;
		return;
	}
	else {
		std::cout << r->data << std::endl;
	}
	_rpre_print(r->left, depth + 1);
	_rpre_print(r->right, depth + 1);
}
