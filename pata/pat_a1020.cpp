#include <cstdio>
#include <queue>
using namespace std;

struct Node_pat_a1020 {
	int data;
	Node_pat_a1020* left{ nullptr }, * right{ nullptr };
	Node_pat_a1020(int data_) : data{data_} {}
};

void level_order_pat_a1020(Node_pat_a1020 *root) {
	queue<Node_pat_a1020*> q;
	Node_pat_a1020* tmp{ nullptr };
	q.push(root);
	int cnt{ 0 };
	while (q.empty() == false) {
		tmp = q.front();
		q.pop();
		if (cnt != 0) {
			printf(" %d", tmp->data);
		}
		else {
			printf("%d", tmp->data);
		}
		++cnt;
		if (tmp->left) {
			q.push(tmp->left);
		}
		if (tmp->right) {
			q.push(tmp->right);
		}
	}
}

Node_pat_a1020 *create_tree_pat_a1020(int postL, int postR, int *postorder, int inL, int inR, int *inorder) {
	if (postL > postR) {
		return nullptr;
	}
	int data = postorder[postR];
	Node_pat_a1020* node = new Node_pat_a1020{ data };
	// 找到中序遍历根节点下标
	int inK{ inL };
	for (; inK <= inR; ++inK) {
		if (inorder[inK] == data) {
			break;
		}
	}
	// 左子树
	node->left = create_tree_pat_a1020(postL, postL+inK-inL-1, postorder, inL, inK-1, inorder);
	// 右子树
	node->right = create_tree_pat_a1020(postL+inK-inL, postR-1, postorder, inK+1, inR, inorder);
	return node;
}

void pat_a1020() {
	/*
	key is distince positive integers
	postorder inorder->level order tranversal
	7
	2 3 1 5 7 6 4
	1 2 3 4 5 6 7

	4 1 6 3 5 7 2
	*/
	int N, postorder[35], inorder[35];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &postorder[i]);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%d", &inorder[i]);
	}
	Node_pat_a1020* root = create_tree_pat_a1020(0, N - 1, postorder, 0, N - 1, inorder);
	level_order_pat_a1020(root);
}

//int main() {
//	pat_a1020();
//	return 0;
//}