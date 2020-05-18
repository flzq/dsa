#pragma once

#include <iostream>
#include <stack>
#include <queue>

template <typename T>
struct BinNode {
	T data;
	int height; // ��¼���ĸ߶ȣ�����AVL����
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

	// �ݹ������������ӡ������
	void rpre_trans();
	// �ݹ������������ӡ������
	void rin_trans();
	// �ݹ������������ӡ������
	void rpost_trans();

	// �����������
	void ipre_trans();
	// �����������
	void iin_trans();
	// ������������
	void ipost_trans();

	// �������
	void level_trans();

	// ����
	bool insert(T x, int pos, T y);
	// �ݹ����������ӡ�������Ľṹ
	void rpre_print();

	// ͳ��Ҷ�ӽڵ�����
	int count();


};



// ͳ��Ҷ�ӽڵ�����
template <typename T>
int BinTree<T>::count() {
	// ���ò������ͳ��Ҷ�ӽڵ�����
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

// �������
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
		// ����
		std::cout << r->data << " ";
		// ������нڵ�
		if (r->left) {
			q.push(r->left);
		}
		if (r->right) {
			q.push(r->right);
		}
	}
	std::cout << std::endl;
}

// ���������������ӡ������
template <typename T>
void BinTree<T>::ipre_trans() {
	BinNode<T>* r = root;
	if (r == nullptr) {
		return;
	}

	std::stack<BinNode<T>*> st;
	while (r) {
		// ���ʸ��ڵ㣬���ڵ���ջ�����·��Ϣ
		std::cout << r->data << " ";
		st.push(r);
		// ����������
		r = r->left;

		// �ж��������Ƿ�Ϊ�գ����и��ڵ㣬Ϊ�����ж��Ƿ����������
		while (r == nullptr && !st.empty()) {
			// ������Ϊ�գ���ջ����ֵ
			r = st.top();
			st.pop();
			// ת��������
			r = r->right;
		}
	}
	std::cout << std::endl;
}
// �����������
template <typename T>
void BinTree<T>::iin_trans() {
	BinNode<T>* r = root;
	if (root == nullptr) {
		return;
	}

	std::stack<BinNode<T>*> st;
	while (r) {
		// ��������������ڵ�����ջ����ջ�ٷ���
		st.push(r);

		// ת��������
		r = r->left;

		// �ж��Ƿ�����������
		// �����������ж�ջ�Ƿ�Ϊ�գ�
		// �����������Ҳ�Ϊ�գ����ջ�������ڵ㣬���ʸ��ڵ㣬��ת��������
		while (r == nullptr && !st.empty()) {
			r = st.top();
			st.pop();
			// ��ջ������������ڵ�
			std::cout << r->data << " ";
			// ת��������
			r = r->right;
		}
	}
	std::cout << std::endl;
}
// ������������
// ��Ϣ�ڵ㣺���ڼ�¼ѭ�����������У��ڵ���ջ�Ĵ������Լ�ջ�ڵ�ĵ�ַ
template <typename T>
struct IBinNode {
	BinNode<T>* root{ nullptr };
	int count{ 0 }; // ��¼�ڵ���ջ�Ĵ���
	IBinNode(BinNode<T>* root_, int count_) : root{ root_ }, count{ count_ } {}
};
template <typename T>
void BinTree<T>::ipost_trans() {
	// ����������ڵ�ڶ��γ�ջ�ٷ���
	BinNode<T>* r = root;
	if (r == nullptr) {
		return;
	}

	IBinNode<T>* tmp_ir{ nullptr }; // �����ݴ��ջ����Ϣ�ڵ�
	// ջ���ڼ���ڵ���ջ�Ĵ������Լ��ڵ��ַ
	std::stack<IBinNode<T>> st;
	while (r) {
		// �����ڵ��ȵ�һ����ջ
		st.push(IBinNode<T>{r, 1});
		//st.push(r);
		//st_count.push(1); // ��¼�ýڵ��һ����ջ

		// ת��������
		r = r->left;
		// �ж��Ƿ���������
		// �����������ж�ջ�Ƿ�Ϊ��
		// ����������ջ��Ϊ�գ����������ڵ��ջ
		// �жϵڼ��γ�ջ����Ϊ��һ�γ�ջ������������������ڵ�ڶ�����ջ
		// Ȼ���������ڵ�ڶ�����ջ��ת��������
		while (r == nullptr && !st.empty()) {
			// �������ڵ��ջ
			tmp_ir = &(st.top());
			st.pop();
			// �жϳ�ջ�Ľڵ���ջ������
			if (tmp_ir->count == 1) {
				// �����ջһ�Σ���ô����ǵ�һ�γ�ջ
				// ת����������Ȼ��ڶ�����ջ
				r = tmp_ir->root->right;
				// �ڶ�����ջ
				st.push(IBinNode<T>{tmp_ir->root, 2});
			}
			else {
				// �����ʾ�Ѿ���ջ���Σ���ô��ξ��ǵڶ��γ�ջ
				// �ڶ��γ�ջ��ֱ�ӷ���
				std::cout << tmp_ir->root->data << " ";
				// ������ýڵ�󣬱�ʾ�Ըýڵ�Ϊ���ڵ�������Ѿ��������ˣ�Ҫ�ص��ýڵ�ĸ��ڵ㣬��˻ص�whileѭ������ʱr==nullptr���ж�ջ�Ƿ�Ϊ�գ�
				// ��Ϊ�գ����ʾ�������ˣ�r = nullptr��stΪ��
				// ���գ�Ȼ�������ջ���õ���γ�ջ���Ѿ����ʽڵ�ĸ��ڵ㣬�ǵ�һ�γ�ջ��Ȼ��ýڵ���ջ��ת��������
			}

		}
	}

	std::cout << std::endl;
}

// �ݹ������������ӡ������
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

// �ݹ������������ӡ������
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
	// ���ò�������ͷŽڵ�
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

// �����������ӡ������
template <typename T>
void BinTree<T>::rpre_trans() {
	_rpre_trans(root);
	std::cout << std::endl;
}
// �ݹ������������ӡ������
template <typename T>
void BinTree<T>::_rpre_trans(BinNode<T>* r) {
	if (r == nullptr) {
		return;
	}
	std::cout << r->data << " ";
	_rpre_trans(r->left);
	_rpre_trans(r->right);
}

// ����
template <typename T>
bool BinTree<T>::insert(T x, int pos, T y) {
	// x��Ҫ����ĸ��ڵ��ֵ
	// pos��Ҫ�����λ�ã�0��������  1��������
	// y��Ҫ�����ֵ
	BinNode<T>* tmp = _rfind(root, x);
	if (tmp == nullptr) {
		return false;
	}
	if (pos == 0) {
		// ��Ϊ���ӽڵ�
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

// �ݹ����ֵΪx�ĵ�ַ
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

// ���������ӡ�������Ľṹ
template <typename T>
void BinTree<T>::rpre_print() {
	_rpre_print(root, 0);
}
// �ݹ�ǰ���ӡ�������Ľṹ
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
