#include <cstdio>
#include <cstring>

void pat_a1050() {
	// 使用hash表记录s2出现的字符，遍历s1，如果出现在s2中，则不输出，否者输出
	char s1[10010], s2[10010];
	bool hash_table[128] = { 0 }; // 记录s2中出现的字符
	fgets(s1, 10010, stdin);
	fgets(s2, 10010, stdin);
	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);
	s1[len_s1 - 1] = 0;
	s2[len_s2 - 1] = 0;
	--len_s1;
	--len_s2;
	// 统计s2中出现的字符，记录在hash_table中
	for (int i = 0; i < len_s2; ++i) {
		hash_table[s2[i]] = true;
	}
	// 遍历s1，输出未出现在s2中的字符
	for (int i = 0; i < len_s1; ++i) {
		if (hash_table[s1[i]] == false) {
			printf("%c", s1[i]);
		}
	}
}

//int main() {
//	pat_a1050();
//	return 0;
//}