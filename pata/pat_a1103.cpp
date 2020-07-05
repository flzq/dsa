#include <cstdio>
#include <cmath>
#include <stack>
using namespace std;

stack<int>  ans;
bool flag = false;

void int_fac_dfs_pat_a1103(int k, int now_k, stack<int>& tmp_kseq, int squr_sum, int N, int K, int P) {
	if (now_k == K && squr_sum == N) {
		ans = tmp_kseq;
		flag = true;
		return;
	}
	if (now_k > K || squr_sum > N) {
		// printf("Impossible");
		return;
	}
	tmp_kseq.push(k);
	int_fac_dfs_pat_a1103(k, now_k+1, tmp_kseq, squr_sum+k*k, N, K, P);
	tmp_kseq.pop();
	int_fac_dfs_pat_a1103(k + 1, now_k, tmp_kseq, squr_sum, N, K, P);
}

void pat_a1103() {
	int N, K, P;
	stack<int> st;
	scanf("%d%d%d", &N, &K, &P);
	int_fac_dfs_pat_a1103(0, 0, st, 0, N, K, P);

	if (flag) {
		printf("%d = ", N);
		int cnt = 0;
		while (ans.empty() == false) {
			if (cnt == 0) {
				printf("%d^%d", ans.top(), P);
			}
			else {
				printf(" + %d^%d", ans.top(), P);
			}
			ans.pop();
			++cnt;
		}
	}
	else {
		printf("Impossible");
	}
}

//int main() {
//	pat_a1103();
//	return 0;
//}