#include <cstdio>

void pat_b1008_simple() {
	/*
		使用简单的方法解决该题：先输出[N-M, N-1]，再输出[0, N-M-1]
	*/
	int N, M;
	int cnt = 0; // 记录已经输出的数

	// 读入数据
	scanf("%d%d", &N, &M);
	int* arr = new int[N];
	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
	}
	M = M % N;

	// 该题中[N-M, N-1]先输出，再输出[0, N-M-1]
	for (int i = N - M; i < N; ++i) {
		++cnt;
		printf("%d", arr[i]);
		if (cnt != N) {
			printf(" ");
		}
	}

	for (int i = 0; i < N - M; ++i) {
		++cnt;
		printf("%d", arr[i]);
		if (cnt != N) {
			printf(" ");
		}
	}

}