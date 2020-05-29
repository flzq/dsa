#include <cstdio>
#include <cmath>

void pat_b1036() {
	int num;
	char c;
	scanf("%d %c", &num, &c);
	int num_lines = (int)round(1.0 * num / 2);
	// 打印第一行
	for (int i = 0; i < num; ++i) {
		printf("%c", c);
	}
	printf("\n");
	// 打印num_lines-2行
	for (int i = 0; i < num_lines - 2; ++i) {
		for (int j = 0; j < num; ++j) {
			if (j == 0 || j == num - 1) {
				printf("%c", c);
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	// 打印最后一行
	for (int i = 0; i < num; ++i) {
		printf("%c", c);
	}
}

//int main() {
//	pat_b1036();
//}