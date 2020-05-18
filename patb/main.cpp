#include <cstdio>

// 用于求Pa部分
long long pa(long long& a, int da) {
	int b;
	long long c{ 0 };
	while (a) {
		b = a % 10;
		a = a / 10;
		if (b == da) {
			c = c * 10 + b;
		}
	}
	return c;
}

void pat_b1016() {
	long long a, b, c;
	int da, db;
	scanf("%lld%d%lld%d", &a, &da, &b, &db);
	printf("%lld", pa(a, da) + pa(b, db));
}

int main() {
	pat_b1016();
	return 0;
}