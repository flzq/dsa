#include <cstdio>

void pat_a1065() {
	/*
		������û��A��Bȡ��2^63�����
	*/
	int T;
	long long a, b, c;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		scanf("%lld%lld%lld", &a, &b, &c);
		long long tmp = a + b;
		if (a > 0 && b > 0 && tmp < 0) { // ���������:[-2, 2^63]
			printf("Case #%d: true\n", i);
		}
		else if (a < 0 && b < 0 && tmp >= 0) { // �������:[0, 2^63-1]
			printf("Case #%d: false\n", i);
		}
		else {
			if (tmp > c) {
				printf("Case #%d: true\n", i);
			}
			else {
				printf("Case #%d: false\n", i);
			}
		}
	}
}