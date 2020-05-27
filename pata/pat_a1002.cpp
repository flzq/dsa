#include <cstdio>
#include <vector>
using std::vector;

/*
	要注意系数相加后，该项可能为0
*/

void pat_a1002() {
	double poly[1010]{ 0 }; // 用于存储相应指数的系数
	int K;
	int exp; // 指数
	double coef; // 系数
	int cnt{ 0 }; // 系数非0项的个数
	scanf("%d", &K);
	// 读入第一个多项式
	while (K--) {
		scanf("%d%lf", &exp, &coef);
		poly[exp] = coef;
	}
	// 读入第二个多项式，并且相加
	scanf("%d", &K);
	while (K--) {
		scanf("%d%lf", &exp, &coef);
		poly[exp] += coef;
	}
	// 计算系数非0项的个数
	for (int i = 0; i <= 1000; ++i) {
		if (poly[i] != 0) {
			++cnt;
		}
	}
	printf("%d", cnt);
	for (int i = 1000; i >= 0; --i) {
		if (poly[i] != 0) {
			printf(" %d %.1f", i, poly[i]);
		}
	}
}


