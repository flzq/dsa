#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Pat_a1045_LIS {
	// 最长不下降子序列解法
	int N, M, L, num{ 0 }, favorite[210], stripe[10010], dp[10010], hash_table[210];
public:
	void pat_a1045() {
		int tmp;
		fill(hash_table, hash_table + 210, -1);
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; ++i) {
			scanf("%d", &favorite[i]);
			hash_table[favorite[i]] = i;
		}
		scanf("%d", &L);
		for (int i = 0; i < L; ++i) {
			scanf("%d", &tmp);
			if (hash_table[tmp] >= 0) {
				stripe[num++] = hash_table[tmp];
			}
		}
		int max_len = -1;
		for (int i = 0; i < num; ++i) {
			dp[i] = 1;
			for (int j = 0; j < i; ++j) {
				if (stripe[j]<=stripe[i] && dp[j] + 1 > dp[i]) {
					dp[i] = 1 + dp[j];
					if (max_len < dp[i]) {
						max_len = dp[i];
					}
				}
			}
		}
		printf("%d", max_len);
	}
};

int dp_LCS[210][10010]{ 0 };
class Pat_a1045_LCS {
	// 最长公共子序列解法
	int N, M, L, favorite[210], stripe[10010];
public:
	void pat_a1045() {
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= M; ++i) {
			scanf("%d", &favorite[i]);
		}
		scanf("%d", &L);
		for (int i = 1; i <= L; ++i) {
			scanf("%d", &stripe[i]);
		}
		for (int i = 0; i <= M; ++i) {
			dp_LCS[i][0] = 0;
		}
		for (int i = 0; i <= L; ++i) {
			dp_LCS[0][i] = 0;
		}
		for (int i = 1; i <= M; ++i) {
			for (int j = 1; j <= L; ++j) {
				if (favorite[i] == stripe[j]) {
					dp_LCS[i][j] = max(dp_LCS[i - 1][j], dp_LCS[i][j - 1]) + 1;
				}
				else {
					dp_LCS[i][j] = max(dp_LCS[i - 1][j], dp_LCS[i][j - 1]);
				}
			}
		}
		printf("%d", dp_LCS[M][L]);
	}
};


//int main() {
//	//Pat_a1045_LIS pat_a1045_lis;
//	//pat_a1045_lis.pat_a1045();
//	Pat_a1045_LCS pat_a1045_lcs;
//	pat_a1045_lcs.pat_a1045();
//	return 0;
//}