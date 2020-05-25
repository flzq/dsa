#include <cstdio>


void shuffle(int* r1, int* r2, int* ordered, int n) { // r1->r2
	for (int i = 0; i < n; ++i) {
		r2[ordered[i] - 1] = r1[i];
	}
}

void pat_a1042() {
	int K; // �ظ�ϴ�ƵĴ���
	int shuffle_ordered[54]; // ϴ�Ƶ����˳��
	int card_record1[54]; // �Ƶ�˳��
	int card_record2[54]; // �Ƶ�˳��card_record1��card_record2������¼ϴ�ƺ��˳��
	const char* card[54] = {
		"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
		"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
		"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
		"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
		"J1", "J2" };
	scanf("%d", &K);
	for (int i = 0; i < 54; ++i) {
		card_record1[i] = i;
		card_record2[i] = i;
	}
	for (int i = 0; i < 54; i++) {
		scanf("%d", &shuffle_ordered[i]);
	}
	for (int i = 0; i < K; ++i) { // ϴ��K��
		if (i % 2 == 0) { // ż����ϴ�ƣ���card_record1->card_record2
			shuffle(card_record1, card_record2, shuffle_ordered, 54);
		}
		else { // ������ϴ�ƣ���card_record2->card_record1
			shuffle(card_record2, card_record1, shuffle_ordered, 54);
		}
	}
	if (K % 2 == 0) { // ϴ�ƴ���Ϊż��
		for (int i = 0; i < 54; ++i) {
			printf("%s", card[card_record1[i]]);
			if (i != 53) {
				printf(" ");
			}
		}
	}
	else { // ϴ�ƴ���Ϊ����
		for (int i = 0; i < 54; ++i) {
			printf("%s", card[card_record2[i]]);
			if (i != 53) {
				printf(" ");
			}
		}
	}

}