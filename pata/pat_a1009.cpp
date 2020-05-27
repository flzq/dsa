#include <cstdio>

void pat_a1009() {
	int K;
	int exp;
	int cnt{ 0 }; // 计算有多少项非0项
	const int MAX = 2010;
	double coef;
	double poly1[MAX]{ 0 };
	double pro_poly[MAX]{ 0 };
	// 读入第一组数据
	scanf("%d", &K);
	while (K--) {
		scanf("%d %lf", &exp, &coef);
		poly1[exp] = coef;
	}
	// 读入第二组数据，并且相乘，然后加到pro_poly对应位置
	scanf("%d", &K);
	while (K--) {
		scanf("%d %lf", &exp, &coef);
		for (int i = 0; i < MAX; ++i) { // 对poly1中的每一项相乘
			if (poly1[i] != 0) {
				pro_poly[i + exp] += coef * poly1[i];
			}
		}
	}
	// 统计非0项
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
