#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node_pat_a1094 {
	int gener{ 1 };
	vector<int> child;
}tree_pat_a1094[110];
int gener_population_pat_a1094[110]{ 0 };

void bfs_pat_a1094(int root) {
	queue<int> q;
	q.push(root);
	tree_pat_a1094[root].gener = 1;
	++gener_population_pat_a1094[1];
	while (q.empty() == false) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < tree_pat_a1094[tmp].child.size(); ++i) {
			int child = tree_pat_a1094[tmp].child[i];
			q.push(child);
			tree_pat_a1094[child].gener = tree_pat_a1094[tmp].gener + 1;
			++gener_population_pat_a1094[tree_pat_a1094[child].gener];
		}
	}
}

void pat_a1094() {
	int N, M, parent, child, num;
	bool is_leaf[110];
	scanf("%d%d", &N, &M);
	fill(is_leaf, is_leaf + N, true);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &parent, &num);
		is_leaf[parent] = false;
		for (int j = 0; j < num; ++j) {
			scanf("%d", &child);
			tree_pat_a1094[parent].child.push_back(child);
		}
	}
	bfs_pat_a1094(1);
	int max{ 1 };
	for (int i = 2; i <= N; ++i) {
		if (gener_population_pat_a1094[i] > max) {
			max = i;
		}
	}
	printf("%d %d", gener_population_pat_a1094[max], max);
}

//int main() {
//	pat_a1094();
//	return 0;
//}