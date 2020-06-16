#include <algorithm>
#include <cstdio>
using std::sort;

double coupons_pat_a1037[100000];
double values_pat_a1037[100000];

bool cmp_pat_a1037(double a, double b) {
	return a > b;
}

void pat_a1037() {
	int Nc, Np;
	// read data
	scanf("%d", &Nc);
	for (int i = 0; i < Nc; ++i) {
		scanf("%lf", &coupons_pat_a1037[i]);
	}
	scanf("%d", &Np);
	for (int i = 0; i < Np; ++i) {
		scanf("%lf", &values_pat_a1037[i]);
	}
	// 由大到小排序
	double money{ 0 };
	sort(coupons_pat_a1037, coupons_pat_a1037 +Nc, cmp_pat_a1037);
	sort(values_pat_a1037, values_pat_a1037 +Np, cmp_pat_a1037);

	// 对正的coupon和value处理
	for (int i = 0, j = 0; i < Nc && j < Np; ++i, ++j) {
		if (coupons_pat_a1037[i] < 0 || values_pat_a1037[j] < 0) {
			break;
		}
		money += coupons_pat_a1037[i] * values_pat_a1037[j];
	}
	// 对负的coupon和value处理
	for (int i = Nc - 1, j = Np - 1; i >= 0, j >= 0; --i, --j) {
		if (coupons_pat_a1037[i] > 0 || values_pat_a1037[j] > 0) {
			break;
		}
		money += coupons_pat_a1037[i] * values_pat_a1037[j];
	}
	printf("%d", (int)money);
}


//int main() {
//	pat_a1037();
//	return 0;
//}