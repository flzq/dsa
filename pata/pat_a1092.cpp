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
	int hash_table[62]; // ��¼�Ƿ������ӣ��Լ����ӵ�����
	bool flag = false; // �Ƿ�ȱ������
	int cnt{ 0 }; // ��¼ȱ�����ӵ�����
	int cnt_z{ 0 }; // ͳ��ʣ�����ӵ�����
	for (int i = 0; i < 62; ++i) {
		hash_table[i] = 0;
	}
	char str1[1010], str2[1010];
	scanf("%s%s", str1, str2);
	int len_str1 = strlen(str1);
	int len_str2 = strlen(str2);
	// ��¼̯�����ӵ�����
	int id;
	for (int i = 0; i < len_str1; ++i) {
		id = hash_func_pat_b1039(str1[i]);
		++hash_table[id];
	}
	// ͳ��
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

	if (flag == true) { // ȱ������
		printf("No %d", cnt);
	}
	else { // ��ȱ
		printf("Yes %d", cnt_z);
	}
}

//int main() {
//	pat_b1039();
//	return 0;
//}