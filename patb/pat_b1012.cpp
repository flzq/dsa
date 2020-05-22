#include <cstdio>

int a[5] = { 0 };
int flag[5] = { 0 }; // 记录某类数字是否存在

void pat_b1012() {
	int N;
	int num;
	int sign = 1;
	int cnt = 0;

	scanf("%d", &N);
	while (N--) {
		scanf("%d", &num);
		if (num % 5 == 0) {
			if (num % 2 == 0) {
				flag[0] = 1;
				a[0] += num;
			}
		}
		else if (num % 5 == 1) {
			flag[1] = 1;
			a[1] += sign * num;
			sign *= -1;
		}
		else if (num % 5 == 2) {
			flag[2] = 1;
			++a[2];
		}
		else if (num % 5 == 3) {
			flag[3] = 1;
			a[3] += num;
			++cnt;
		}
		else if (num % 5 == 4) {
			if (num > a[4]) {
				flag[4] = 1;
				a[4] = num;
			}
		}
	}
	double aver = (double)a[3] / cnt;

	for (int i = 0; i < 5; ++i) {
		if (flag[i]) {
			if (i != 3) {
				printf("%d", a[i]);
			}
			else {
				printf("%.1f", aver);
			}
		}
		else {
			printf("N");
		}
		if (i < 4) {
			printf(" ");
		}
	}



}