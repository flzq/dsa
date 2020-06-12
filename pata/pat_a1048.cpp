#include <cstdio>

void pat_a1048() {
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

//int main() {
//	pat_a1048();
//	return 0;
//}