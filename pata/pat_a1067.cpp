#include <cstdio>

void pat_a1067() {
	int N; // ��¼��0��������ĸ���
	int k{ 1 }; // ��1��ʼö�����������±�, ��ֹʹ��ѭ����ʱ, ��k==Nʱ��ʾ��������������
	int num[100000];
	int inx[100000]; // ����λ�õ�����
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &num[i]);
		inx[num[i]] = i;
		if (num[i] != i && i!=0) {
		}
	}
	int cnt{ 0 }; // ��¼swap�Ĵ���
	while (k < N) { // ��1��ʼö�����������±�, ��ֹʹ��ѭ����ʱ, ��k==Nʱ��ʾ��������������
		if (inx[0] != 0) { // ÿ�ν���, ��һ�����ֶ�����
			// printf("(%d, %d) ", 0, inx[0]); // ��ӡһ��ת��swap(0, *)
			int index = inx[0];
			int tmp = inx[0];
			inx[0] = inx[index];
			inx[index] = tmp;
			++cnt;
		}
		else {
			// �ж�ȫ��������û���ź�
			// ʹ��ѭ���ҵ�û���źõ�����, ���²��Ե�1, 2��ʱ
			// ���ʹ�� k ��1��ʼö�����������±�, ��ֹʹ��ѭ����ʱ
			//for (int i = 1; i < N; ++i) {
			//	if (inx[i] != i) {
			//		inx[0] = inx[i];
			//		inx[i] = 0;
			//		flag = false;
			//		++cnt;
			//		break;
			//	}
			//}
			//if (flag) {
			//	break;
			//}
			while (k < N) {
				if (inx[k] != k) {
					inx[0] = inx[k];
					inx[k] = 0;
					++cnt;
					break;
				}
				++k;
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