#include <cstdio>
#include <cstring>

void pat_a1077() {
	int N;
	char lines[100][257];
	bool flag{ true }; // 有共同后缀
	scanf("%d\n", &N);
	for (int i = 0; i < N; ++i) {
		fgets(lines[i], 257, stdin);
	}

	// 先从前两行中找到共同的后缀
	int len_a = strlen(lines[0]);
	int len_b = strlen(lines[1]);
	char suffix[257];
	int cnt{ 0 }; // 计算后缀的字符数
	for (len_a -= 2, len_b-=2; len_a >= 0 && len_b >= 0; --len_a, --len_b) {
		// --len_a, --len_b: 因为每个字符串最后有一个换行符,所以要从换行符前一个字符开始比较
		if (lines[0][len_a] == lines[1][len_b] && lines[0][len_a] != ' ' && lines[1][len_b] != ' ') {
			suffix[cnt++] = lines[1][len_b];
		}
		else {
			break;
		}
	}
	suffix[cnt] = '\0';
	if (cnt == 0) { // 表示前两个字符就没有相同后缀
		flag = false;
	}
	// 从第三个字符开始比较是否有共同的后缀
	for (int i = 2; i < N; ++i) {
		len_a = strlen(lines[i]);
		len_a -= 2;
		int j;
		for (j = 0; j < cnt && len_a>=0; ++j, --len_a) {
			if (suffix[j] != lines[i][len_a]) {
				flag = false;
				break;
			}
		}
		if (flag == false || j < cnt) { // 表示lines[i] 中没有该后缀
			flag = false;
			break;
		}

	}

	if (flag == false) {
		printf("nai");
	}
	else {
		for (int i = cnt - 1; i >= 0; --i) {
			printf("%c", suffix[i]);
		}
	}


}


//int main() {
//	pat_a1077();
//	return 0;
//}