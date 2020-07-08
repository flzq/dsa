#include <cstdio>
#include <vector>
using namespace std;

struct Node_pat_a1079 {
	double price;
	double product;
	vector<int> child;
}tree_pat_a1079[100010];

void dfs_pat_a1079(int id, double r) {
	// 用于计算每个节点的零售价格
	for (int i = 0; i < tree_pat_a1079[id].child.size(); ++i) {
		int child = tree_pat_a1079[id].child[i];
		tree_pat_a1079[child].price = tree_pat_a1079[id].price * (1 + r/100.0);
		dfs_pat_a1079(child, r);
	}
}

void pat_a1079() {
	int N, num, child;
	vector<int> leaf_id; // 记录叶节点id
	double P, r;
	// 读入数据
	scanf("%d%lf%lf", &N, &P, &r);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &num);
		if (num) {
			for (int j = 0; j < num; ++j) {
				scanf("%d", &child);
				tree_pat_a1079[i].child.push_back(child);
			}
		}
		else {
			scanf("%lf", &tree_pat_a1079[i].product);
			leaf_id.push_back(i);
		}
	}
	// 计算每个节点的售价
	tree_pat_a1079[0].price = P;
	dfs_pat_a1079(0, r);
	double sum{ 0 };
	for (int i = 0; i < leaf_id.size(); ++i) {
		sum += tree_pat_a1079[leaf_id[i]].price * tree_pat_a1079[leaf_id[i]].product;
	}
	printf("%.1f", sum);
}

//int main() {
//	pat_a1079();
//	return 0;
//}