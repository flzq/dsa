#include <cstdio>

void pat_b1008_simple() {
	/*
		ʹ�ü򵥵ķ���������⣺�����[N-M, N-1]�������[0, N-M-1]
	*/
	int N, M;
	int cnt = 0; // ��¼�Ѿ��������

	// ��������
	scanf("%d%d", &N, &M);
	int* arr = new int[N];
	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
	}
	M = M % N;

	// ������[N-M, N-1]������������[0, N-M-1]
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