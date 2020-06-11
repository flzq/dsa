#include <cstdio>
#include <cstring>

bool hash_table[63];

int hash_func(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A';
	}
	else if (c >= 'a' && c <= 'z') {
		return c - 'a';
	}
	else if (c >= '0' && c <= '9') {
		return c - '0' + 26;
	}
	else {
		return c - '-' + 36;
	}
}

void pat_a1084() {
	char str1[81], str2[81];
	scanf("%s%s", str1, str2);
	int len_str1 = strlen(str1);
	int len_str2 = strlen(str2);
	int index_str1 = 0, index_str2 = 0;
	for (int i = 0; i < 63; ++i) {
		hash_table[i] = false;
	}
	while (index_str2 < len_str2) {
		if (str1[index_str1] != str2[index_str2]) {
			int id = hash_func(str1[index_str1]);
			if (hash_table[id] == false) {
				hash_table[id] = true;
				if (str1[index_str1] >= 'a' && str1[index_str2] <= 'z') {
					printf("%c", str1[index_str1] - 32);
				}
				else {
					printf("%c", str1[index_str1]);
				}
			}
			++index_str1;
		}
		else {

			++index_str1;
			++index_str2;
		}
	}
	while (index_str1 < len_str1) {
		int id = hash_func(str1[index_str1]);
		if (hash_table[id] == false) {
			hash_table[id] = true;
			printf("%c", str1[index_str1]);
		}
		++index_str1;
	}
}