#include <cstdio>

void pat_a1009() {
	int K;
	int exp;
	int cnt{ 0 }; // �����ж������0��
	const int MAX = 2010;
	double coef;
	double poly1[MAX]{ 0 };
	double pro_poly[MAX]{ 0 };
	// �����һ������
	scanf("%d", &K);
	while (K--) {
		scanf("%d %lf", &exp, &coef);
		poly1[exp] = coef;
	}
	// ����ڶ������ݣ�������ˣ�Ȼ��ӵ�pro_poly��Ӧλ��
	scanf("%d", &K);
	while (K--) {
		scanf("%d %lf", &exp, &coef);
		for (int i = 0; i < MAX; ++i) { // ��poly1�е�ÿһ�����
			if (poly1[i] != 0) {
				pro_poly[i + exp] += coef * poly1[i];
			}
		}
	}
	// ͳ�Ʒ�0��
	for (int i = 0; i < MAX; ++i) {
		if (pro_poly[i] != 0) {
			++cnt;
		}
	}
	printf("%d", cnt);
	for (int i = MAX - 1; i >= 0; --i) {
		if (pro_poly[i] != 0) {
			printf(" %d %.1f", i, pro_poly[i]);
		}
	}
}
