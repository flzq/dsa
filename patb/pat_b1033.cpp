#include <cstdio>
#include <cstring>

void pat_b1033() {
	// ��֤�ڶ�������ǿգ���˿���û�л��ļ�
	char str1[100010], str2[100010];
	bool hash_table[128];
	for (int i = 0; i < 128; ++i) {
		hash_table[i] = false;
	}
	fgets(str1, 100005, stdin);
	fgets(str2, 100005, stdin);
	// ȥ������Ļ���
	str1[strlen(str1) - 1] = 0;
	str2[strlen(str2) - 1] = 0;
	int len_str1 = strlen(str1);
	int len_str2 = strlen(str2);
	if (len_str1) {
		// ��hash_table��Ӧ��λ����Ϊtrue����ʾ��λ����
		for (int i = 0; i < len_str1; ++i) {
			if (str1[i] >= 'A' && str1[i] <= 'Z') {
				hash_table[str1[i]] = true;
				hash_table[str1[i] + 32] = true;
			}
			else {
				hash_table[str1[i]] = true;
			}
		}
		for (int i = 0; i < len_str2; ++i) {
			if (hash_table[str2[i]] == false) {
				if (str2[i] >= 'A' && str2[i] <= 'Z') { // ��д��ĸ�ж��ϵ����Ƿ����
					if (hash_table['+'] == false) {
						printf("%c", str2[i]);
					}
				}
				else {
					printf("%c", str2[i]);
				}
			}
		}
	}
	else { // û�л��ļ�
		puts(str2);
	}
}

//int main() {
//	pat_b1033();
//
//	return 0;
//}