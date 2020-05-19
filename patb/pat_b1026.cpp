#include <cstdio>

void pat_b1026() {
	int CLK_TCK = 100;
	int c1, c2;
	scanf("%d%d", &c1, &c2);
	int clk_tck = c2 - c1;
	int ss = clk_tck / CLK_TCK;
	ss += (clk_tck % CLK_TCK >= 50 ? 1 : 0);

	/*int hh = ss / 3600;
	ss = ss - hh * 3600;
	int mm = ss / 60;
	ss = ss - mm * 60;
	printf("%02d:%02d:%02d", hh, mm, ss);*/
	printf("%02d:%02d:%02d", ss / 3600, ss % 3600 / 60, ss % 60);
}