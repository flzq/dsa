#include <cstdio>
#include <cstring>

void pat_b1024() {
	// ��ͨ���ֲ���Ҫ�������
	char ch1, ch2;
	char ch[10010];
	int index_E{ 0 }; // ��ʾE��λ��
	int exp{ 0 }, len;
	double tmp;
	scanf("%s", ch);
	len = strlen(ch);
	// �ҵ�E��λ��
	while (ch[index_E] != 'E') {
		++index_E;
	}
	// �ҵ�ָ����С
	for (int i = index_E+2; i < len; ++i) {
		exp = exp * 10 + (ch[i] - '0');
	}

	// �������
	if (ch[0] == '-') {
		printf("%c", ch[0]);
	}
	// �ж�ָ������
	if (ch[index_E + 1] == '+') { // ָ��Ϊ��
		// ָ��Ϊ��ʱ, Ҫע����û��С����
		printf("%c", ch[1]);
		int index_dec{ 3 }; // �ӿ�ѧ��������С�����ֿ�ʼ
		for (int i = 0; i < exp; ++i) {
			if (index_dec < index_E) {
				printf("%c", ch[index_dec++]);
			}
			else {
				printf("0");
			}
		}
		// �����ѧ�������е�С�����ֻ�û�������,����С����
		if (index_dec < index_E) {
			printf(".");
			while (index_dec < index_E) {
				printf("%c", ch[index_dec++]);
			}
		}

	}
	else { // ָ��Ϊ��
		for (int i = 0; i < exp; ++i) {
			printf("0");
			if (i == 0) {
				printf(".");
			}
		}
		for (int i = 1; i < index_E; ++i) {
			if (i != 2) {
				printf("%c", ch[i]);
			}
		}
	}
}


//int main() {
//	pat_b1024();
//	return 0;
//}