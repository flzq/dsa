#include <cstdio>
#include <cstring>

int hash_func_pat_b1039(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A';
	}
	else if (c >= 'a' && c <= 'z') {
		return c - 'a' + 26;
	}
	else {
		return c - '0' + 52;
	}
}

void pat_b1039() {
	int hash_table[62]; // 记录是否有珠子，以及主子的数量
	bool flag = false; // 是否缺少珠子
	int cnt{ 0 }; // 记录缺少珠子的数量
	int cnt_z{ 0 }; // 统计剩余珠子的数量
	for (int i = 0; i < 62; ++i) {
		hash_table[i] = 0;
	}
	char str1[1010], str2[1010];
	scanf("%s%s", str1, str2);
	int len_str1 = strlen(str1);
	int len_str2 = strlen(str2);
	// 记录摊主珠子的数量
	int id;
	for (int i = 0; i < len_str1; ++i) {
		id = hash_func_pat_b1039(str1[i]);
		++hash_table[id];
	}
	// 统计
	for (int i = 0; i < len_str2; ++i) {
		id = hash_func_pat_b1039(str2[i]);
		if (hash_table[id] > 0) {
			--hash_table[id];
		}
		else {
			flag = true;
			++cnt;
		}
	}
	for (int i = 0; i < 62; ++i) {
		cnt_z += hash_table[i];
	}

	if (flag == true) { // 缺少珠子
		printf("No %d", cnt);
	}
	else { // 不缺
		printf("Yes %d", cnt_z);
	}
}

//int main() {
//	pat_b1039();
//	return 0;
//}