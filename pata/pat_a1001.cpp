#include <cstdio>
#include <cstring>

void print(char* dig, int len) {
	int left = len % 3; // �����������Ҫ��������ٸ�����
	int cnt{ 0 }, flag{ 0 }; // flag���ڼ����Ƿ��ӡ","
	// ��ӡ��λ
	while (cnt < left) {
		printf("%c", dig[cnt]);
		++cnt;
	}
	// �����λ��ӡ֮��������,����Ҫ��ӡ ","
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
	// ��������Ҫ��� "+"
	long long a, b, c;
	int len;
	char dig[8];
	scanf("%lld%lld", &a, &b);
	c = a + b;
	if (c >= 0) {
		// ��������Ҫ��� "+"
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