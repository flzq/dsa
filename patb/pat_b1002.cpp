#include <cstdio>
#include <cstring>

void pat_b1002() {
	char N[110];
	int digits[4];
	const char* py[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	scanf("%s", N);
	int len = strlen(N);
	int sum{ 0 };
	for (int i = 0; i < len; ++i) {
		sum += N[i] - '0';
	}
	int cnt{ 0 };
	do {
		digits[cnt++] = sum % 10;
		sum = sum / 10;
	} while (sum != 0);
	for (int i = cnt - 1; i >= 0; --i) {
		printf("%s", py[digits[i]]);
		if (i != 0) {
			printf(" ");
		}
	}
}

//int main() {
//	pat_b1002();
//
//	return 0;
//}