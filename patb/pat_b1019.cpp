#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;

bool cmp_pat_b1019(char a, char b) {
	return a > b;
}
int trans_num_pat_b1019(char* str) {
	int res{ 0 };
	for (int i = 0; i < 4; ++i) {
		res = res * 10 + (str[i] - '0');
	}
	return res;
}

void pat_b1019() {
	char str[5];
	char tmp_str[5];
	int tmp_num;
	scanf("%d", &tmp_num);
	sprintf(str, "%04d", tmp_num);
	// 比较是否与相等
	bool flag = true;
	for (int i = 1; i < 4; ++i) {
		if (str[i] != str[0]) {
			flag = false;
			break;
		}
	}
	if (flag == false) {
		do {
			flag = false;
			sort(str, str + 4, cmp_pat_b1019);
			printf("%s ", str);
			strcpy(tmp_str, str);
			sort(str, str + 4);
			printf("- %s = ", str);
			// 转化为整型数字
			int num1 = trans_num_pat_b1019(tmp_str);
			int num2 = trans_num_pat_b1019(str);
			printf("%04d", num1 - num2);
			if (num1 - num2 == 6174) {
				flag = true;
			}
			sprintf(str, "%04d", num1 - num2);

			printf("\n");
		} while (flag == false);
	}
	else {
		printf("%s - %s = 0000", str, str);
	}
}

//int main() {
//	pat_b1019();
//
//	return 0;
//}