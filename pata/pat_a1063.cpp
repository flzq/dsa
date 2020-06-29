#include <cstdio>
#include <set>
#include <algorithm>
using std::set;
using std::swap;


void pat_a1063_2() {
	int N, M, K, num, id1, id2;
	set<int> s[50];

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &M);
		for (int j = 0; j < M; ++j) {
			scanf("%d", &num);
			s[i].insert(num);
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d%d", &id1, &id2);
		int common{ 0 }; // 记录相同元素数量
		--id1;
		--id2;
		// id1存储长度更小的集合id， id2存储长度更长的集合id
		if (s[id1].size() > s[id2].size()) {
			swap(id1, id2);
		}
		for (set<int>::iterator it = s[id1].begin(); it != s[id1].end(); ++it) {
			if (s[id2].find(*it) != s[id2].end()) {
				++common;
			}
		}
		printf("%.1f%%\n", (common * 1.0) / ((s[id1].size() + s[id2].size() - common)) * 100.0);
	}
}


//int main() {
//	pat_a1063_2();
//	return 0;
//}