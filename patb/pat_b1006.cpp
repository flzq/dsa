#include <cstdio>

void pat_b1006() {
	int n;
	int b, s, g;
	scanf("%d", &n);
	b = n / 100;
	s = n % 100 / 10;
	g = n % 10;
	for (int i = 0; i < b; ++i) {
		printf("B");
	}
	for (int i = 0; i < s; ++i) {
		printf("S");
	}
	for (int i = 1; i <= g; ++i) {
		printf("%d", i);
	}
}

//int main() {
//	pat_b1006();
//	return 0;
//}