#include <cstdio>
#include <vector>
using std::vector;

double pro_poly[1000010]{ 0 };


void pat_a1009() {
	int K;
	int exp;
	int cnt{ 0 }; // �����ж������0��
	double coef;
	double poly1[1010]{ 0 };
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
		for (int i = 0; i <= 1000; ++i) { // ��poly1�е�ÿһ�����
			if (poly1[i] != 0) {
				pro_poly[i + exp] += coef * poly1[i];
			}
		}
	}
	// ͳ�Ʒ�0��
	for (int i = 0; i < 1000010; ++i) {
		if (pro_poly[i] != 0) {
			++cnt;
		}
	}
	printf("%d", cnt);
	for (int i = 1000010; i >= 0; --i) {
		if (pro_poly[i] != 0) {
			printf(" %d %.1f", i, pro_poly[i]);
		}
	}
}

