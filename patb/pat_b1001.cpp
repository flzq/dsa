#include <cstdio>

bool is_even(int n) {
	return n % 2 == 0;
}

void pat_b1001() {
	int n{ 0 };
	int count{ 0 };
	scanf("%d", &n);
	while (n != 1) {
		if (is_even(n)) {
			n = n / 2;
		}
		else {
			n = (3 * n + 1) / 2;
		}
		++count;
	}
	printf("%d", count);
}
