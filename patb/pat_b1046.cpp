#include <cstdio>

void pat_b1046() {
	int N, a_1, a_2, b_1, b_2, c;
	int count_a{ 0 }, count_b{ 0 }; // ¼×ÒÒºÈ¾ÆµÄ´ÎÊý
	scanf("%d", &N);
	while (N--) {
		scanf("%d%d%d%d", &a_1, &a_2, &b_1, &b_2);
		c = a_1 + b_1;
		if (c == a_2 && c != b_2) {
			++count_b;
		}
		else if (c != a_2 && c == b_2) {
			++count_a;
		}
	}
	printf("%d %d", count_a, count_b);
}