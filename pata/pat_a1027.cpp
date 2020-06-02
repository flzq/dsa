#include <cstdio>

void transform(int color, int* digs) {
	int base = 13; // 13½øÖÆ
	int cnt{ 0 };
	do {
		digs[cnt++] = color % base;
		color = color / base;
	} while (color != 0);
	if (cnt == 1) {
		digs[1] = 0;
	}
}

void pat_a1027() {
	int rgb[3];
	int digs[2];
	char charac[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C' };
	scanf("%d%d%d", &rgb[0], &rgb[1], &rgb[2]);
	printf("#");
	for (int i = 0; i < 3; ++i) {
		transform(rgb[i], digs);
		printf("%c%c", charac[digs[1]], charac[digs[0]]);
	}
}


//int main() {
//	pat_a1027();
//}