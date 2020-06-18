#include <cstdio>
#include <cstring>

int change_pat_a1010(char *digits, int base, int len) {
	// 转换为10进制
	long long num{ 0 };
	for (int i = 0; i < len; ++i) {
		if (digits[i] >= '0' && digits[i] <= '9') {
			num = num * base + (digits[i] - '0');
		}
		else {
			num = num * base + (digits[i] - 'a' + 10);
		}

	}
	return num;
}

int solve(int num, char* digits, int len) {
	long num2;
	for (int i = 2; i < 37; ++i) {
		num2 = change_pat_a1010(digits, i, len);
		if (num == num2) {
			return i;
		}
	}
	return -1;
}

void pat_a1010() {
	char digits1[11], digits2[11];
	int tag, radix;
	long long num1;
	scanf("%s%s%d%d", digits1, digits2, &tag, &radix);
	int len_digits1 = strlen(digits1);
	int len_digits2 = strlen(digits2);

	if (tag == 1) {
		num1 = change_pat_a1010(digits1, radix, len_digits1);
		int base2 = solve(num1, digits2, len_digits2);
		if (base2 == -1) {
			printf("Impossible");
		}
		else {
			printf("%d", base2);
		}
	}
	else {
		num1 = change_pat_a1010(digits2, radix, len_digits2);
		int base2 = solve(num1, digits1, len_digits1);
		if (base2 == -1) {
			printf("Impossible");
		}
		else {
			printf("%d", base2);
		}
	}
}

//int main() {
//	pat_a1010();
//
//	return 0;
//}