#include <cstdio>

void pat_a1041() {
	// ��һ��ѡ��һ��ֻ��һ����ѡ������Ӯ
	int hash_table[10010]; // ÿ�����ֳ��ֵĴ���
	for (int i = 0; i < 10010; ++i) {
		hash_table[i] = 0;
	}
	// ��¼N����ѡ������
	int num[100010];
	int N, number;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &number);
		++hash_table[number];
		num[i] = number;
	}
	// indexΪֻ����һ�ε�����[1, 10e4]
	int index{ 0 };
	for (int i = 0; i < N; ++i) {
		if (hash_table[num[i]] == 1) {
			index = num[i];
			break;
		}
	}
	if (index) {
		printf("%d", index);
	}
	else {
		printf("None");
	}

}

//int main() {
//	pat_a1041();
//	return 0;
//}