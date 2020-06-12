#include <cstdio>
#include <cstring>

void pat_b1042() {
	char str[1010];
	int hash_table[128]; // 记录字符出现次数
	for (int i = 0; i < 128; ++i) {
		hash_table[i] = 0;
	}
	fgets(str, 1010, stdin);
	int len_str = strlen(str);
	str[len_str - 1] = 0; // 去掉换行符
	--len_str;
	for (int i = 0; i < len_str; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') { // 将大写字母转化为小写字母
			++hash_table[str[i] + 32];
		}
		else {
			++hash_table[str[i]];
		}
	}
	// 统计出现最频繁的英文字母（不区分大小写），并列输出字母序最小
	int max{ 0 }, index_max;
	for (int i = 'a'; i < 'z' + 1; ++i) {
		if (hash_table[i] > max) {
			max = hash_table[i];
			index_max = i;
		}
	}
	printf("%c %d", index_max, max);
}

//int main() {
//	pat_b1042();
//	return 0;
//}