#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node_pat_a1106 {
	double price;
	vector<int> child;
}tree_pat_a1106[100010];
bool is_leaf_pat_a1106[100010]{ false };

void dfs_pat_a1106(int root, double r) {
	for (int i = 0; i < tree_pat_a1106[root].child.size(); ++i) {
		int child = tree_pat_a1106[root].child[i];
		tree_pat_a1106[child].price = tree_pat_a1106[root].price * (1 + r / 100.0);
		dfs_pat_a1106(child, r);
	}
}

void pat_a1106() {
	int N, num, child;
	double P, r;
	scanf("%d%lf%lf", &N, &P, &r);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &num);
		if (num) {
			for (int j = 0; j < num; ++j) {
				scanf("%d", &child);
				tree_pat_a1106[i].child.push_back(child);
			}
		}
		else {
			is_leaf_pat_a1106[i] = true;
		}
	}
	tree_pat_a1106[0].price = P;
	dfs_pat_a1106(0, r);
	double min_price{ 10000000000 };
	int cnt{ 0 };
	for (int i = 0; i < N; ++i) {
		if (is_leaf_pat_a1106[i]) {
			if (tree_pat_a1106[i].price < min_price) {
				min_price = tree_pat_a1106[i].price;
				cnt = 1;
			}
			else if (tree_pat_a1106[i].price == min_price) {
				++cnt;
			}
		}
	}
	printf("%.4f %d", min_price, cnt);
}

//int main() {
//	pat_a1106();
//	return 0;
//}