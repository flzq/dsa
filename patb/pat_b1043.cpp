#include <cstdio>
#include <cstring>

void pat_b1043() {
	char str[10010];
	int hash_table[128]; // 统计各种字符出现次数
	for (int i = 0; i < 128; ++i) {
		hash_table[i] = 0;
	}
	scanf("%s", str);
	int len_str = strlen(str);
	for (int i = 0; i < len_str; ++i) {
		++hash_table[str[i]];
	}
	// 统计PATest出现的次数
	int cnt_P = hash_table['P'];
	int cnt_A = hash_table['A'];
	int cnt_T = hash_table['T'];
	int cnt_e = hash_table['e'];
	int cnt_s = hash_table['s'];
	int cnt_t = hash_table['t'];
	while (cnt_P || cnt_A || cnt_T || cnt_e || cnt_s || cnt_t) {
		if (cnt_P) {
			printf("P");
			--cnt_P;
		}
		if (cnt_A) {
			printf("A");
			--cnt_A;
		}
		if (cnt_T) {
			printf("T");
			--cnt_T;
		}
		if (cnt_e) {
			printf("e");
			--cnt_e;
		}
		if (cnt_s) {
			printf("s");
			--cnt_s;
		}
		if (cnt_t) {
			printf("t");
			--cnt_t;
		}
	}

}

//int main() {
//	pat_b1043();
//	return 0;
//}