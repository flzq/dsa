#include <cstdio>

bool is_leap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void pat_b1022() {
	int a, b, c, D, cnt{ 0 };
	int dig[32]{ 0 };
	scanf("%d%d%d", &a, &b, &D);
	c = a + b;
	do {
		dig[cnt++] = c % D;
		c = c / D;
	} while (c != 0);
	for (int i = cnt - 1; i >= 0; --i) {
		printf("%d", dig[i]);
	}
}

int main() {
	pat_b1022();
}