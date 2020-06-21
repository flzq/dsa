#include <cstdio>

void pat_a1048() {
	// 使用hash_table
	// 测试点3：注意v2，要v2>=0 && v2<=500, 防止v2越界
	int N, M;
	int hash_table[510]{ 0 }; // 相应面值硬币的数量
	scanf("%d%d", &N, &M);
	for (int i = 0, coin; i < N; ++i) {
		scanf("%d", &coin);
		++hash_table[coin];
	}
	bool flag = false; // 是否有解
	for (int v1 = 1, v2; v1 < 501; ++v1) {
		// v1<=v2
		if (hash_table[v1] != 0) {
			--hash_table[v1];
			v2 = M - v1;
			if (v2 >= 0 && v2 <= 500 && hash_table[v2] != 0 && v2 >= v1) { // v2>=0 && v2<=500：防止v2越界
				flag = true;
				printf("%d %d", v1, v2);
				break;
			}
		}
	}
	if (flag == false) {
		printf("No Solution");
	}
}

void pat_a1048_2() {
	// 使用二分法
	int N, M;
	int coins[100000];
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &coins[i]);
	}
	// V1从第0枚开始枚举
	int flag = true; // 有解决方案
	for (int i = 0; i < N; ++i) {
		int V1 = coins[i];
		// 从[i+1, N+1]找到面值刚好为M-V1的coin
		int left = i + 1, right = N + 1, mid;
		while (left < right) {
			mid = (left + right) / 2;

		}
	}
}

//int main() {
//	pat_a1048();
//	return 0;
//}