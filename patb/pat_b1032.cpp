#include <cstdio>

const int max = 100000;
int info[max + 1] = { 0 };

void pat_b1032() {
	int n{ 0 }, max_id{ 1 };
	int id, score;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &id, &score);
		info[id] += score;
	}

	for (int i = 2; i < max + 1; ++i) {
		if (info[i] > info[max_id]) {
			max_id = i;
		}
	}
	printf("%d %d", max_id, info[max_id]);
}