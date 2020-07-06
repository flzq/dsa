#include <cstdio>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

int max_sum_fac_pat_a1103{ -1 };

void int_fac_dfs_pat_a1103(int index, int now_k, int sum_squr, int sum_fac,
	vector<int>& ans, vector<int>& tmp_ans, vector<int>& vkp, vector<int>& vk, int N, int K, int P) {
	if (now_k == K && sum_squr == N) {
		if (sum_fac > max_sum_fac_pat_a1103) {
			ans = tmp_ans;
			max_sum_fac_pat_a1103 = sum_fac;
		}
		return;
	}
	if (now_k > K || sum_squr > N || index < 1) {
		return;
	}

	// 继续选择index
	tmp_ans.push_back(index);
	int_fac_dfs_pat_a1103(index, now_k + 1, sum_squr + vkp[index], sum_fac + vk[index],
		ans, tmp_ans, vkp, vk, N, K, P);
	tmp_ans.pop_back();
	// 不选index
	int_fac_dfs_pat_a1103(index - 1, now_k, sum_squr, sum_fac, ans, tmp_ans, vkp, vk, N, K, P);
}

void pat_a1103() {
	int N, K, P;
	vector<int> ans, tmp_ans, vkp, vk; // ans存储最后的结果; tmp_ans存储中间结果
	scanf("%d%d%d", &N, &K, &P);
	for (int i = 0; (int)pow(i, P) < N; ++i) {
		vkp.push_back((int)pow(i, P));
		vk.push_back(i);
	}

	int_fac_dfs_pat_a1103(vkp.size()- 1, 0, 0, 0, ans, tmp_ans, vkp, vk, N, K, P);
	if (ans.empty()) {
		printf("Impossible");
	}
	else {
		printf("%d =", N);
		for (int i = 0; i < ans.size(); ++i) {
			if (i != 0) {
				printf(" + %d^%d", ans[i], P);
			}
			else {
				printf(" %d^%d", ans[i], P);
			}
		}
	}

}

//int main() {
//	pat_a1103();
//	return 0;
//}