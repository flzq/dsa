#include <cstdio>
#include <cmath>

void pat_b1036() {
	int num;
	char c;
	scanf("%d %c", &num, &c);
	int num_lines = (int)round(1.0 * num / 2);
	// ��ӡ��һ��
	for (int i = 0; i < num; ++i) {
		printf("%c", c);
	}
	printf("\n");
	// ��ӡnum_lines-2��
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
	// ��ӡ���һ��
	for (int i = 0; i < num; ++i) {
		printf("%c", c);
	}
}

//int main() {
//	pat_b1036();
//}