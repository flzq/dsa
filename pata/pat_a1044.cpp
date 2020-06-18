#include <cstdio>

int lower_pat_a1044(int i, int N, int M, int* sum_diamonds) {
	// 从[i, N]找
	int left = i, right = N, mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (i == 0) {
			if (sum_diamonds[mid] >= M) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		else {
			if (sum_diamonds[mid] - sum_diamonds[i - 1] >= M) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
	}
	return left;
}

void pat_a1044() {
	// 找第一个满足条件>=M
	int N, M;
	int diamonds[100000];
	int sum_diamonds[100000]; // sum_diamonds[i]之前的和(包括位置i)
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &diamonds[i]);
		if (i > 0) {
			sum_diamonds[i] = diamonds[i] + sum_diamonds[i - 1];
		}
		else {
			sum_diamonds[i] = diamonds[i];
		}
	}
	// 找到第一个 >=M 的数,然后比较差值(0或较小的数),找插值最小的
	int res{ 1010 }, tmp_res;
	for (int i = 0; i < N; ++i) {
		// 从[i, N-1]找一个位置
		int mid = lower_pat_a1044(i, N, M, sum_diamonds);
		if (mid != N) {
			if (i == 0) {
				tmp_res = sum_diamonds[mid] - M;
			}
			else {
				tmp_res = sum_diamonds[mid] - sum_diamonds[i - 1] - M;
			}
			if (tmp_res >= 0 && tmp_res < res) {
				res = tmp_res;
			}
		}
	}
	 //printf("%d", res);
	// 由上面得到了最小插值res(>=0)
	// 再通过一个for循环输出
	for (int i = 0; i < N; ++i) {
		int mid = lower_pat_a1044(i, N, M + res, sum_diamonds);
		if (mid != N && sum_diamonds[mid]) {
			if (i == 0) {
				if (sum_diamonds[mid] == M + res) {
					printf("%d-%d\n", i + 1, mid + 1);
				}
			}
			else {
				if (sum_diamonds[mid] - sum_diamonds[i - 1] == M + res) {
					printf("%d-%d\n", i + 1, mid + 1);
				}
			}
		}
	}
}


//int main() {
//	pat_a1044();
//
//	return 0;
//}