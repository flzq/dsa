#include <cstdio>
#include <algorithm>
using namespace std;

struct Node_pat_a1066 {
	int key;
	int height{ 1 };
	Node_pat_a1066* lchild{ nullptr }, * rchild{ nullptr };
	Node_pat_a1066(int key_) : key{ key_ } {}
};

int get_height_pat_a1066(Node_pat_a1066* root) {
	if (root == nullptr) {
		return 0;
	}
	return root->height;
}

void update_height_pat_a1066(Node_pat_a1066* root) {
	root->height = max(get_height_pat_a1066(root->lchild), get_height_pat_a1066(root->rchild)) + 1;
}

int get_balance_factor_pat_a1066(Node_pat_a1066* root) {
	return get_height_pat_a1066(root->lchild) - get_height_pat_a1066(root->rchild);
}

void L_rotation_pat_a1066(Node_pat_a1066 *&root) {
	Node_pat_a1066* tmp = root->rchild;
	root->rchild = tmp->lchild;
	tmp->lchild = root;
	update_height_pat_a1066(root);
	update_height_pat_a1066(tmp);
	root = tmp;
}

void R_rotation_pat_a1066(Node_pat_a1066*& root) {
	Node_pat_a1066* tmp = root->lchild;
	root->lchild = tmp->rchild;
	tmp->rchild = root;
	update_height_pat_a1066(root);
	update_height_pat_a1066(tmp);
	root = tmp;

}

void insert_pat_a1066(Node_pat_a1066*& root, int key) {
	if (root == nullptr) {
		root = new Node_pat_a1066(key);
		return;
	}
	if (key < root->key) {
		insert_pat_a1066(root->lchild, key);
		update_height_pat_a1066(root);
		if (get_balance_factor_pat_a1066(root) == 2) {
			if (get_balance_factor_pat_a1066(root->lchild) == 1) {
				R_rotation_pat_a1066(root);
			}
			else if (get_balance_factor_pat_a1066(root->lchild) == -1) {
				L_rotation_pat_a1066(root->lchild);
				R_rotation_pat_a1066(root);
			}
		}
	}
	else {
		insert_pat_a1066(root->rchild, key);
		update_height_pat_a1066(root);
		if (get_balance_factor_pat_a1066(root) == -2) {
			if (get_balance_factor_pat_a1066(root->rchild) == -1) {
				L_rotation_pat_a1066(root);
			}
			else if (get_balance_factor_pat_a1066(root->rchild) == 1) {
				R_rotation_pat_a1066(root->rchild);
				L_rotation_pat_a1066(root);
			}
		}

	}
}

void pat_a1066() {
	int N, key;
	Node_pat_a1066* root{ nullptr };
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &key);
		insert_pat_a1066(root, key);
	}
	printf("%d", root->key);

}

//int main() {
//	pat_a1066();
//	return 0;
//}