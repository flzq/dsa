#include <cstdio>
#include <algorithm>
using std::sort;

void pat_b1005() {
	bool hash_table[110]{ false }; // ��¼ĳ�����Ƿ�����������
	int num[100]{ 0 }; // ��¼���������
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d", &num[i]);
		// ��������ֵ�1������������
		for (int j = num[i]; j != 1;) {
			if (j % 2 == 0) {
				j /= 2;
			}
			else{
				j = (3 * j + 1) / 2;
			}
			if (j > 1 && j <= 100) {
				hash_table[j] = true;
			}
		}
	}
	// ͳ�ƹؼ�������
	int cnt{ 0 };
	for (int i = 0; i < K; ++i) {
		if (hash_table[num[i]] == false) {
			++cnt;
		}
	}
	// �Ӵ�С����ؼ���
	// ��������������
	sort(num, num + K);
	for (int i = K - 1; i >= 0; --i) {
		if (hash_table[num[i]] == false) {
			printf("%d", num[i]);
			--cnt;
			//if (i != 0) { // ע�⣺���м�ĳ������������涼�����ʱ������ո���ʽ����, ��"_"���Կ������������Ҫ��cnt����
			//	printf("_");
			//}
			if (cnt > 0) {
				printf(" ");
			}
		}
	}
}

//int main() {
//	pat_b1005();
//	return 0;
//}