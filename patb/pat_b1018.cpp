/*
	���Ե�3δͨ��
*/

#include <cstdio>


void pat_b1018() {
	char c1, c2;
	int cnt1[2][3]{ 0 }; // ��¼���Ҹ�������ʤ�Ĵ���, ����������B-0, C-1, J-2
	int cnt2[2][3]{ 0 }; // ��¼���ҵ�ʤ��ƽ�����Ĵ���
	char ss[3] = { 'B', 'C', 'J' };
	int N;
	scanf("%d", &N);
	while (N--) {
		scanf("\n%c %c", &c1, &c2);
		if (c1 == 'C') {
			if (c2 == 'C') { // ƽ
				cnt2[0][1] += 1;
				cnt2[1][1] += 1;
			}
			else if (c2 == 'J') { // ��ʤ���Ҹ�
				++cnt1[0][1];
				++cnt2[0][0];
				++cnt2[1][2];
			}
			else { // c2 == 'B' �׸�����ʤ
				++cnt1[1][0];
				++cnt2[0][2];
				++cnt2[1][0];
			}
		}
		else if (c1 == 'J') {
			if (c2 == 'C') { // �׸�
				++cnt1[1][1];
				++cnt2[0][2];
				++cnt2[1][0];
			}
			else if (c2 == 'J') { // ƽ
				cnt2[0][1] += 1;
				cnt2[1][1] += 1;
			}
			else { // c2 == 'B' ��ʤ
				++cnt1[0][2];
				++cnt2[0][0];
				++cnt2[1][2];
			}
		}
		else { // c1 == 'B'
			if (c2 == 'C') { // ��ʤ
				++cnt1[0][0];
				++cnt2[0][0];
				++cnt2[1][2];
			}
			else if (c2 == 'J') { // �׸�
				++cnt1[1][2];
				++cnt2[0][2];
				++cnt2[1][0];
			}
			else { // c2 == 'B' ƽ
				cnt2[0][1] += 1;
				cnt2[1][1] += 1;
			}
		}
	}

	// ������һ�ʤ������������
	int num_1_id = 0;
	int num_2_id = 0;
	for (int i = 1; i < 3; ++i) {
		if (cnt1[0][i] > cnt1[0][num_1_id]) {
			num_1_id = i;
		}
		if (cnt1[1][i] > cnt1[1][num_1_id]) {
			num_1_id = i;
		}
	}

	printf("%d %d %d\n", cnt2[0][0], cnt2[0][1], cnt2[0][2]);
	printf("%d %d %d\n", cnt2[1][0], cnt2[1][1], cnt2[1][2]);
	printf("%c %c\n", ss[num_1_id], ss[num_2_id]);
}