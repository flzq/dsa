#include <cstdio>

void pat_b1038() {
	int hash_table[110]; // 记录相应分数的人数
	int N, K, score;
	for (int i = 0; i < 110; ++i) {
		hash_table[i] = 0;
	}
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &score);
		++hash_table[score];
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d", &score);
		printf("%d", hash_table[score]);
		if (i < K - 1) {
			printf(" ");
		}
	}
}


int main() {
	pat_b1038();

	return 0;
}