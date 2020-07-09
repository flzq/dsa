#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Node_pat_a1090 {
	double price;
	vector<int> child;
}tree_pat_a1090[100010];
bool is_leaf_pat_a1090[100010];

void dfs_pat_a1090(int root, double r) {
	// 计算每个节点的价格
	for (int i = 0; i < tree_pat_a1090[root].child.size(); ++i) {
		int child = tree_pat_a1090[root].child[i];
		tree_pat_a1090[child].price = tree_pat_a1090[root].price * (1 + r / 100.0);
		dfs_pat_a1090(child, r);
	}
}

void pat_a1090() {
	int N, parent, root;
	double P, r;
	scanf("%d%lf%lf", &N, &P, &r);
	fill(is_leaf_pat_a1090, is_leaf_pat_a1090 + N, true);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &parent);
		if (parent != -1) {
			tree_pat_a1090[parent].child.push_back(i);
			is_leaf_pat_a1090[parent] = false;
		}
		else {
			root = i;
		}
	}
	tree_pat_a1090[root].price = P;
	dfs_pat_a1090(root, r);
	double max_price{ 0 };
	int cnt{ 0 };
	for (int i = 0; i < N; ++i) {
		if (is_leaf_pat_a1090[i]) {
			if (max_price < tree_pat_a1090[i].price) {
				max_price = tree_pat_a1090[i].price;
				cnt = 1;
			}
			else if (max_price == tree_pat_a1090[i].price) {
				++cnt;
			}
		}
	}
	printf("%.2f %d", max_price, cnt);
}

//int main() {
//	pat_a1090();
//	return 0;
//}