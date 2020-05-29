#include <cstdio>

void pat_a1011() {
	double odds[3][3];
	double max_odds[3] = { 0 };
	int max_id[3] = { 0 };
	char c[3] = { 'W', 'T', 'L' };
	for (int i = 0; i < 3; ++i) {
		scanf("%lf%lf%lf", &odds[i][0], &odds[i][1], &odds[i][2]);
		for (int j = 0; j < 3; ++j) {
			if (odds[i][j] > max_odds[i]) {
				max_odds[i] = odds[i][j];
				max_id[i] = j;
			}
		}
	}
	double profit = (odds[0][max_id[0]] * odds[1][max_id[1]] * odds[2][max_id[2]]*0.65 - 1) * 2;
	printf("%c %c %c %.2f", c[max_id[0]], c[max_id[1]], c[max_id[2]], profit);
}


int main() {
	pat_a1011();
}