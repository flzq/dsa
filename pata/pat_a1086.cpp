#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

struct Node_pat_a1086 {
	int data;
	Node_pat_a1086* left{ nullptr }, * right{ nullptr };
	Node_pat_a1086(int data_) : data{ data_ } {}
};

Node_pat_a1086* create_pat_a1086(int preL, int preR, vector<int>& pre_order, int inL, int inR, vector<int>& in_order) {
	if (preL > preR) {
		return nullptr;
	}
	int data = pre_order[preL];
	Node_pat_a1086* node = new Node_pat_a1086(data);
	int inK{ inL };
	for (; inK <= inR; ++inK) {
		if (in_order[inK] == data) {
			break;
		}
	}
	// ×ó×ÓÊ÷
	node->left = create_pat_a1086(preL+1, preL+inK-inL, pre_order, inL, inK-1, in_order);
	// ÓÒ×ÓÊ÷
	node->right = create_pat_a1086(preL+inK-inL+1, preR, pre_order, inK+1, inR, in_order);
	return node;
}

void post_trans_pat_a1086(Node_pat_a1086 *root, int& cnt) {
	if (root == nullptr) {
		return;
	}
	post_trans_pat_a1086(root->left, cnt);
	post_trans_pat_a1086(root->right, cnt);
	if (cnt == 0) {
		printf("%d", root->data);
		++cnt;
	}
	else {
		printf(" %d", root->data);
		++cnt;
	}

}

void pat_a1086() {
	int N, data;
	char op[6];
	vector<int> pre_order, in_order;
	stack<int> st;
	scanf("%d", &N);
	for (int i = 0; i < 2 * N; ++i) {
		scanf("%s", op);
		if (strcmp(op, "Push") == 0) {
			scanf("%d", &data);
			pre_order.push_back(data);
			st.push(data);
		}
		else {
			in_order.push_back(st.top());
			st.pop();
		}
	}
	Node_pat_a1086 *root =  create_pat_a1086(0, N-1, pre_order, 0, N-1, in_order);
	int cnt{ 0 };
	post_trans_pat_a1086(root, cnt);

}

//int main() {
//	pat_a1086();
//	return 0;
//}