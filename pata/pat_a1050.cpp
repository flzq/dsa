#include <cstdio>
#include <cstring>

void pat_a1050() {
	// ʹ��hash���¼s2���ֵ��ַ�������s1�����������s2�У���������������
	char s1[10010], s2[10010];
	bool hash_table[128] = { 0 }; // ��¼s2�г��ֵ��ַ�
	fgets(s1, 10010, stdin);
	fgets(s2, 10010, stdin);
	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);
	s1[len_s1 - 1] = 0;
	s2[len_s2 - 1] = 0;
	--len_s1;
	--len_s2;
	// ͳ��s2�г��ֵ��ַ�����¼��hash_table��
	for (int i = 0; i < len_s2; ++i) {
		hash_table[s2[i]] = true;
	}
	// ����s1�����δ������s2�е��ַ�
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