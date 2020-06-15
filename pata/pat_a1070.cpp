#include <cstdio>
#include <algorithm>
using std::sort;
// pat_b1020/ pat_a1070
struct Moon_pat_b1020 {
	double amount;
	double avg_price;
};

bool cmp_pat_b1020(Moon_pat_b1020& a, Moon_pat_b1020& b) {
	return a.avg_price < b.avg_price;
}

void pat_b1020() {
	int N;
	double D;
	Moon_pat_b1020 moon[1000];
	scanf("%d%lf", &N, &D);
	for (int i = 0; i < N; ++i) {
		scanf("%lf", &moon[i].amount);
	}
	double price;
	for (int i = 0; i < N; ++i) {
		scanf("%lf", &price);
		moon[i].avg_price = price / moon[i].amount;
	}
	// 由小到大排序
	sort(moon, moon + N, cmp_pat_b1020);
	double total_net{ 0 };
	for (int i = N - 1; i >= 0 && D > 0; --i) {
		if (D >= moon[i].amount) {
			total_net += moon[i].amount * moon[i].avg_price;
			D -= moon[i].amount;
		}
		else {
			total_net += D * moon[i].avg_price;
			D = 0;
		}
	}
	printf("%.2f", total_net);
}


//int main() {
//	pat_b1020();
//
//	return 0;
//}