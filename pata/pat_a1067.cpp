#include <cstdio>


void pat_a1067() {
	int N, cnt_per; // ��¼�����
	int num[100000];
	int inx[100000]; // ����λ�õ�����
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &num[i]);
		inx[num[i]] = i;
	}
	int cnt{ 0 }; // ��¼swap�Ĵ���
	while (true) {
		if (inx[0] != 0) {
			// printf("(%d, %d) ", 0, inx[0]); // ��ӡһ��ת��swap(0, *)
			int index = inx[0];
			int tmp = inx[0];
			inx[0] = inx[index];
			inx[index] = tmp;
			++cnt;
		}
		else {
			bool flag = true; // ���ֶ��ź���
			// �ж�ȫ��������û���ź�
			for (int i = 1; i < N; ++i) {
				if (inx[i] != i) {
					inx[0] = inx[i];
					inx[i] = 0;
					flag = false;
					++cnt;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
	}
	printf("%d", cnt);
}


//int main() {
//	pat_a1067();
//
//	return 0;
//}