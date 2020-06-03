#include <cstdio>
#include <cstring>

void pat_b1024() {
	// 普通数字不需要输出正号
	char ch1, ch2;
	char ch[10010];
	int index_E{ 0 }; // 表示E的位置
	int exp{ 0 }, len;
	double tmp;
	scanf("%s", ch);
	len = strlen(ch);
	// 找到E的位置
	while (ch[index_E] != 'E') {
		++index_E;
	}
	// 找到指数大小
	for (int i = index_E+2; i < len; ++i) {
		exp = exp * 10 + (ch[i] - '0');
	}

	// 输出负号
	if (ch[0] == '-') {
		printf("%c", ch[0]);
	}
	// 判断指数正负
	if (ch[index_E + 1] == '+') { // 指数为正
		// 指数为正时, 要注意有没有小数点
		printf("%c", ch[1]);
		int index_dec{ 3 }; // 从科学计数法的小数部分开始
		for (int i = 0; i < exp; ++i) {
			if (index_dec < index_E) {
				printf("%c", ch[index_dec++]);
			}
			else {
				printf("0");
			}
		}
		// 如果科学计数法中的小数部分还没有输出完,则都是小数了
		if (index_dec < index_E) {
			printf(".");
			while (index_dec < index_E) {
				printf("%c", ch[index_dec++]);
			}
		}

	}
	else { // 指数为负
		for (int i = 0; i < exp; ++i) {
			printf("0");
			if (i == 0) {
				printf(".");
			}
		}
		for (int i = 1; i < index_E; ++i) {
			if (i != 2) {
				printf("%c", ch[i]);
			}
		}
	}
}


//int main() {
//	pat_b1024();
//	return 0;
//}