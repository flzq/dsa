#include <cstdio>

void pat_b1023() {
	int digs[10]; // 记录每个数字的个数
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &digs[i]);
	}
	// 先输出非0的一位
	for (int i = 1; i < 10; ++i) {
		if (digs[i]) {
			printf("%d", i);
			--digs[i];
			break;
		}
	}
	for (int i = 0; i < 10; ++i) {
		if (digs[i]) {
			for (int j = 0; j < digs[i]; ++j) {
				printf("%d", i);
			}
		}
	}
}


//int main() {
//	pat_b1023();
//	return 0;
//}