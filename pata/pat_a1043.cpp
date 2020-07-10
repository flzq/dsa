#include <cstdio>
#include <vector>
using namespace std;

struct Node_pat_a1043 {
	int data;
	Node_pat_a1043* lchild{ nullptr }, * rchild{ nullptr };
	Node_pat_a1043(int data_) : data{ data_ } {}
};

Node_pat_a1043* insert_pat_a1043(Node_pat_a1043* root, int data) {
	if (root == nullptr) {
		root = new Node_pat_a1043(data);
		return root;
	}
	if (data < root->data) {
		root->lchild = insert_pat_a1043(root->lchild, data);
	}
	else {
		root->rchild = insert_pat_a1043(root->rchild, data);
	}
	return root;
}

void pre_order_pat_a1043(Node_pat_a1043* root, vector<int>& pre_order) {
	if (root == nullptr) {
		return;
	}
	pre_order.push_back(root->data);
	pre_order_pat_a1043(root->lchild, pre_order);
	pre_order_pat_a1043(root->rchild, pre_order);
}
void pre_order_mirror_pat_a1043(Node_pat_a1043* root, vector<int>& pre_order_mirror) {
	if (root == nullptr) {
		return;
	}
	pre_order_mirror.push_back(root->data);
	pre_order_pat_a1043(root->rchild, pre_order_mirror);
	pre_order_pat_a1043(root->lchild, pre_order_mirror);
}
void post_order_pat_a1043(Node_pat_a1043* root, vector<int>& post_order) {
	if (root == nullptr) {
		return;
	}
	post_order_pat_a1043(root->lchild, post_order);
	post_order_pat_a1043(root->rchild, post_order);
	post_order.push_back(root->data);
}
void post_order_mirror_pat_a1043(Node_pat_a1043* root, vector<int>& post_order_mirror) {
	if (root == nullptr) {
		return;
	}
	post_order_pat_a1043(root->rchild, post_order_mirror);
	post_order_pat_a1043(root->lchild, post_order_mirror);
	post_order_mirror.push_back(root->data);
}

void print_pat_a1043(vector<int> order) {
	printf("YES\n");
	for (int i = 0; i < order.size(); ++i) {
		printf("%d", order[i]);
		if (i < order.size() - 1) {
			printf(" ");
		}
	}
}

void pat_a1043() {
	int N, data;
	vector<int> origion, pre_order, pre_order_mirror, post_order, post_order_mirror;
	Node_pat_a1043* root{ nullptr };
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &data);
		origion.push_back(data);
		root = insert_pat_a1043(root, data);// create bst tree
	}
	pre_order_pat_a1043(root, pre_order);
	pre_order_mirror_pat_a1043(root, pre_order_mirror);
	post_order_pat_a1043(root, post_order);
	post_order_mirror_pat_a1043(root, post_order_mirror);
	if (origion == pre_order) {
		print_pat_a1043(post_order);
	}
	else if (origion == pre_order_mirror) {
		print_pat_a1043(post_order_mirror);
	}
	else {
		printf("NO\n");
	}

}

//int main() {
//	pat_a1043();
//	return 0;
//}