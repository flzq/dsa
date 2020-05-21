#include <cstdio>

void pat_b1008() {
	/*
		pat_b1008_simple：未对原数组进行操作
		但是按照题意，要用最少的移动次数
		可能的解法：
			当 N % M == 0 时，数组不需要移动，移动0次
			当 N % M != 0 时，数组最少的移动次数应该为数组个数（猜测）
				从 N-M 位置进行移动，一共移动 N 次，则能得到顺序
	*/
	int N, M;
	scanf("%d%d", &N, &M);
	// 读入数据
	int* data = new int[N];
	for (int i = 0; i < N; ++i) {
		scanf("%d", &data[i]);
	}
	M = M % N;
	int cnt{ 0 }; // 计算移动了几次
	if (M != 0) { // M不为0则需要移动，否则直接输出
		// 从N-M位置的元素开始移动
		for (int i = N - M, tmp, tmp_idx; i < N; ++i) {
			tmp = data[i];
			tmp_idx = i;
			while ((tmp_idx - M + N) % N != i) {
				data[tmp_idx] = data[(tmp_idx - M + N) % N];
				tmp_idx = (tmp_idx - M + N) % N;
				++cnt;
			}
			data[tmp_idx] = tmp;
			++cnt;
			if (cnt == N) {
				break;
			}
		}
	}
	// 输出
	for (int i = 0; i < N; ++i) {
		if (i != N - 1) {
			printf("%d ", data[i]);
		}
		else {
			printf("%d", data[i]);
		}
	}
}