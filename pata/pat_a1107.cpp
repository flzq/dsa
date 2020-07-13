#include <cstdio>
#include <algorithm>
using namespace std;

int father_pat_a1107[1010];

void init_pat_a1107() {
	for (int i = 1; i <= 1000; ++i) {
		father_pat_a1107[i] = -1;
	}
}

int find_father_pat_a1107(int a) {
	while (father_pat_a1107[a] > 0) {
		a = father_pat_a1107[a];
	}
	return a;
}

void union_set_pat_a1107(int a, int b) {
	int fa = find_father_pat_a1107(a);
	int fb = find_father_pat_a1107(b);
	if (fa != fb) {
		father_pat_a1107[fa] += father_pat_a1107[fb];
		father_pat_a1107[fb] = fa;
	}
}

void pat_a1107() {
	int N, K, hobby;
	int hobbies[1010]{ 0 }; // 记录第一个喜欢该hobby的人的编号
	scanf("%d", &N);
	init_pat_a1107();
	for (int i = 1; i <= N; ++i) {
		scanf("%d: ", &K);
		for (int j = 0; j < K; ++j) {
			scanf("%d", &hobby);
			if (hobbies[hobby] == 0) {
				hobbies[hobby] = i;
			}
			union_set_pat_a1107(i, hobbies[hobby]);
		}
	}
	int cnt{ 0 };
	for (int i = 1; i <= N; ++i) {
		if (father_pat_a1107[i] < 0) {
			++cnt;
		}
	}
	printf("%d\n", cnt);
	sort(father_pat_a1107 + 1, father_pat_a1107 + N + 1);
	for (int i = 1; i <= cnt; ++i) {
		printf("%d", -father_pat_a1107[i]);
		if (i < cnt) {
			printf(" ");
		}
	}
}

//int main() {
//	pat_a1107();
//	return 0;
//}