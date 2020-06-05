#include <cstdio>
#include <cstring>


void pat_b1048() {
	// 测试点2, 5 未通过
	char a[110], b[110], c[110]{ 0 };
	char dig[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K' };
	scanf("%s%s", &a, &b);
	int len_a, len_b;
	len_a = strlen(a);
	len_b = strlen(b);

	int cnt{ 1 };
	int tmp;
	while (len_a > 0 && len_b > 0) {
		if (cnt % 2 == 0) { // 偶数位
			tmp = b[len_b-1] - a[len_a-1];
			if (tmp < 0) {
				tmp += 10;
			}
		}
		else { // 奇数位
			tmp = (a[len_a-1] - '0') + (b[len_b-1] - '0');
			tmp = tmp % 13;
		}
		c[cnt] = dig[tmp];
		++cnt;
		--len_a;
		--len_b;
	}
	while (len_b > 0) {
		c[cnt++] = b[len_b-1];
		len_b--;
	}
	for (int i = cnt - 1; i >= 1; --i) {
		printf("%c", c[i]);
	}
}

//int main() {
//	pat_b1048();
//	return 0;
//}