#include <cstdio>

void pat_b1023() {
	int digs[10]; // ��¼ÿ�����ֵĸ���
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &digs[i]);
	}
	// �������0��һλ
	for (int i = 1; i < 10; ++i) {
		if (digs[i]) {
			printf("%d", i);
			--digs[i];
			break;
		}
	}
	for (int i = 0; i < 10; ++i) {
		if (digs[i]) {
			for (int j = 0; j < digs[i]; ++j) {
				printf("%d", i);
			}
		}
	}
}


//int main() {
//	pat_b1023();
//	return 0;
//}