#include <cstdio>
#include <cstring>

void print(char* dig, int len) {
	int left = len % 3; // 计算最左边需要先输出多少个数字
	int cnt{ 0 }, flag{ 0 }; // flag用于计算是否打印","
	// 打印高位
	while (cnt < left) {
		printf("%c", dig[cnt]);
		++cnt;
	}
	// 如果高位打印之后还有数字,则需要打印 ","
	if (left != 0 && cnt < len) {
		printf(",");
	}

	while (cnt < len) {
		printf("%c", dig[cnt]);
		++cnt;
		++flag;
		flag = flag % 3;
		if (flag == 0 && cnt < len) {
			printf(",");
		}
	}
}

void pat_a1001() {
	// 正数不需要输出 "+"
	long long a, b, c;
	int len;
	char dig[8];
	scanf("%lld%lld", &a, &b);
	c = a + b;
	if (c >= 0) {
		// 正数不需要输出 "+"
		// printf("+");
		int cnt{ 0 };
		sprintf(dig, "%lld", c);
		len = strlen(dig);
		print(dig, len);
	}
	else {
		printf("-");
		c = -c;
		sprintf(dig, "%d", c);
		len = strlen(dig);
		print(dig, len);
	}
}


//int main() {
//	pat_a1001();
//	return 0;
//}