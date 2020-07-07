#include <cstdio>
#include <queue>
using namespace std;

struct Node_pat_a1102 {
	int left, right;
}tree_pat_a1102[15];
bool is_root_pat_a1102[15];

void level_order_pat_a1102(int root) {
	queue<int> q;
	q.push(root);
	int cnt{ 0 };
	while (q.empty() == false) {
		root = q.front();
		q.pop();
		if (cnt == 0) {
			printf("%d", root);
		}
		else {
			printf(" %d", root);
		}
		++cnt;
		if (tree_pat_a1102[root].left != -1) {
			q.push(tree_pat_a1102[root].left);
		}
		if (tree_pat_a1102[root].right != -1) {
			q.push(tree_pat_a1102[root].right);
		}
	}

}

void in_order_pat_a1102(int root, int& cnt) {
	if (root == -1) {
		return;
	}
	in_order_pat_a1102(tree_pat_a1102[root].left, cnt);
	if (cnt != 0) {
		printf(" %d", root);
	}
	else {
		printf("%d", root);
	}
	++cnt;
	in_order_pat_a1102(tree_pat_a1102[root].right, cnt);
}

void invert_tree_pat_a1102(int root) {
	if (root == -1) {
		return;
	}
	int tmp = tree_pat_a1102[root].left;
	tree_pat_a1102[root].left = tree_pat_a1102[root].right;
	tree_pat_a1102[root].right = tmp;
	invert_tree_pat_a1102(tree_pat_a1102[root].left);
	invert_tree_pat_a1102(tree_pat_a1102[root].right);
}

void pat_a1102() {
	int N;
	char left, right;
	scanf("%d", &N);
	fill(is_root_pat_a1102, is_root_pat_a1102 + N, true);
	getchar();
	for (int i = 0; i < N; ++i) {
		scanf("%c %c", &left, &right);
		getchar();
		if (left == '-') {
			tree_pat_a1102[i].left = -1;
		}
		else {
			tree_pat_a1102[i].left = left - '0';
			is_root_pat_a1102[tree_pat_a1102[i].left] = false;
		}
		if (right == '-') {
			tree_pat_a1102[i].right = -1;
		}
		else {
			tree_pat_a1102[i].right = right - '0';
			is_root_pat_a1102[tree_pat_a1102[i].right] = false;
		}
	}
	// 找到根节点
	int root;
	for (root = 0; root < N; ++root) {
		if (is_root_pat_a1102[root]) {
			break;
		}
	}
	invert_tree_pat_a1102(root);
	level_order_pat_a1102(root);
	printf("\n");
	int cnt{ 0 };
	in_order_pat_a1102(root, cnt);
}

//int main() {
//	pat_a1102();
//	return 0;
//}