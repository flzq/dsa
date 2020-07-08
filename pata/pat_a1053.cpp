#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Node_pat_a1053 {
	int weight;
	vector<int> child;
}tree_pat_a1053[110];

void dfs_pat_a1053(int id, int sum_weight, vector<int>& path_weight, int S) {
	if (sum_weight == S) {
		if (tree_pat_a1053[id].child.size() == 0) {
			for (int i = 0; i < path_weight.size(); ++i) {
				if (i != 0) {
					printf(" %d", path_weight[i]);
				}
				else {
					printf("%d", path_weight[i]);
				}
			}
			printf("\n");
		}
		return;
	}

	for (int i = 0; i < tree_pat_a1053[id].child.size(); ++i) {
		path_weight.push_back(tree_pat_a1053[tree_pat_a1053[id].child[i]].weight);
		dfs_pat_a1053(tree_pat_a1053[id].child[i], sum_weight + tree_pat_a1053[tree_pat_a1053[id].child[i]].weight, path_weight, S);
		path_weight.pop_back();
	}

}

bool cmp_pat_a1053(int a, int b) {
	return tree_pat_a1053[a].weight > tree_pat_a1053[b].weight;
}

void pat_a1053() {
	int N, M, S, id, num, child;
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &tree_pat_a1053[i].weight);
	}
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &id, &num);
		for (int j = 0; j < num; ++j) {
			scanf("%d", &child);
			tree_pat_a1053[id].child.push_back(child);
		}
		sort(tree_pat_a1053[id].child.begin(), tree_pat_a1053[id].child.end(), cmp_pat_a1053);
	}

	vector<int> path_weight;
	path_weight.push_back(tree_pat_a1053[0].weight);
	dfs_pat_a1053(0, tree_pat_a1053[0].weight, path_weight, S);
}

//int main() {
//	pat_a1053();
//	return 0;
//}