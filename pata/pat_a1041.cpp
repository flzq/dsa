#include <cstdio>

void pat_a1041() {
	// 第一个选了一个只有一个人选的数字赢
	int hash_table[10010]; // 每个数字出现的次数
	for (int i = 0; i < 10010; ++i) {
		hash_table[i] = 0;
	}
	// 记录N个人选的数字
	int num[100010];
	int N, number;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &number);
		++hash_table[number];
		num[i] = number;
	}
	// index为只出现一次的数字[1, 10e4]
	int index{ 0 };
	for (int i = 0; i < N; ++i) {
		if (hash_table[num[i]] == 1) {
			index = num[i];
			break;
		}
	}
	if (index) {
		printf("%d", index);
	}
	else {
		printf("None");
	}

}

//int main() {
//	pat_a1041();
//	return 0;
//}