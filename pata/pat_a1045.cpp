#include <cstdio>

class Pat_a1045 {
	int N, M, L, favorite[200], stripe[10000], dp[10000];
public:
	void pat_a1045() {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; ++i) {
			scanf("%d", &favorite[i]);
		}
		scanf("%d", &L);
		for (int i = 0; i < L; ++i) {
			scanf("%d", &stripe[i]);
		}
		int max_len = -1;
		for (int i = 0; i < L; ++i) {
			dp[i] = find_origin(i);
			if (dp[i] == 0) {
				continue;
			}
			for (int j = 0; j < i; ++j) {
				if (dp[j]>=1 && get_index(j)<=get_index(i) && dp[j] + dp[i] > dp[i]) {
					dp[i] = 1 + dp[j];
					if (max_len < dp[i]) {
						max_len = dp[i];
					}
				}
			}
		}
		printf("%d", max_len);
	}
	int get_index(int index) {
		for (int i = 0; i < M; ++i) {
			if (stripe[index] == favorite[i]) {
				return i;
			}
		}
	}
	int find_origin(int index) {
		// 找到最初dp中是包含该位置的颜色
		for (int i = 0; i < M; ++i) {
			if (stripe[index] == favorite[i]) {
				return 1;
			}
		}
		return 0;
	}
};

//int main() {
//	Pat_a1045 pat_a1045;
//	pat_a1045.pat_a1045();
//	return 0;
//}