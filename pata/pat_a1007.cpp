#include <cstdio>
#include <algorithm>
using namespace std;

class Pat_a1007 {
	int K, num[10000], dp[10000], index[10000];
public:
	void pat_a1007() {
		// 注意处理全负的情况
		bool flag = true;
		scanf("%d", &K);
		for (int i = 0; i < K; ++i) {
			scanf("%d", &num[i]);
			if (num[i] >= 0) {
				flag = false;
			}
		}
		if (flag) {
			printf("0 %d %d", num[0], num[K-1]);
		}
		else {
			dp[0] = num[0];
			index[0] = 0;
			for (int i = 1; i < K; ++i) {
				if (num[i] > num[i] + dp[i - 1]) {
					dp[i] = num[i];
					index[i] = i;
				}
				else {
					dp[i] = num[i] + dp[i - 1];
					index[i] = index[i - 1];
				}
				dp[i] = max(num[i], num[i] + dp[i - 1]);
			}

			int max_index{ 0 };
			for (int i = 1; i < K; ++i) {
				if (dp[i] > dp[max_index]) {
					max_index = i;
				}
			}
			printf("%d %d %d", dp[max_index], num[index[max_index]], num[max_index]);
		}
	}
};

int main() {
	Pat_a1007 pat_a1007;
	pat_a1007.pat_a1007();
	return 0;
}