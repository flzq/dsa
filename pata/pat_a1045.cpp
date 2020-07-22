#include <cstdio>
#include <algorithm>
using namespace std;

class Pat_a1045 {
	int N, M, L, num{ 0 }, favorite[200], stripe[10000], dp[10000], hash_table[210];
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

//int main() {
//	Pat_a1045 pat_a1045;
//	pat_a1045.pat_a1045();
//	return 0;
//}