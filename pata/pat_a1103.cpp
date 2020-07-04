#include <cstdio>
#include <cmath>

void int_fac_dfs_pat_a1103(int k, int now_k, int N, int K, int P) {

}

void pat_a1103() {
	int N, K, P;
	scanf("%d%d%d", &N, &K, &P);
	printf("%d", (int)sqrt(N));
	int_fac_dfs_pat_a1103(1, 1, N, K, P);
}

//int main() {
//	pat_a1103();
//	return 0;
//}