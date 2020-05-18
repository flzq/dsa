#include <cstdio>


void pat_b1011() {
	int n, count{ 0 };
	long long a, b, c;
	scanf("%d", &n);
	while (n--) {
		++count;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a + b > c) {
			printf("Case #%d: true\n", count);
		}
		else {
			printf("Case #%d: false\n", count);
		}

	}
}

