#include <cstdio>

// ���е�Ǯת��������
int trans_knut(int g, int s, int k) {
	int tmp = 0;
	tmp = g * 17 * 29 + s * 29 + k;
	return tmp;
}

void pat_b1037() {
	int pg, ps, pk; // Ӧ����Ǯ
	int ag, as, ak; // ʵ����Ǯ
	int cg, cs, ck; // �����Ǯ
	scanf("%d.%d.%d %d.%d.%d", &pg, &ps, &pk, &ag, &as, &ak);
	// ������Ǯת��������
	int p_k = trans_knut(pg, ps, pk);
	int a_k = trans_knut(ag, as, ak);
	int gap = p_k < a_k ? (a_k - p_k) : (p_k - a_k);
	cg = gap / (17 * 29);
	cs = gap % (17 * 29) / 29;
	ck = gap % 29;
	if (p_k <= a_k) {
		printf("%d.%d.%d", cg, cs, ck);
	}
	else { // ������Ǯ
		printf("-%d.%d.%d", cg, cs, ck);
	}
}

//
//int main() {
//	pat_b1037();
//}