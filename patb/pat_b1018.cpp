/*
	测试点3未通过
*/

#include <cstdio>


void pat_b1018() {
	char c1, c2;
	int cnt1[2][3]{ 0 }; // 记录甲乙各种手势胜的次数, 手势索引：B-0, C-1, J-2
	int cnt2[2][3]{ 0 }; // 记录甲乙的胜、平、负的次数
	char ss[3] = { 'B', 'C', 'J' };
	int N;
	scanf("%d", &N);
	while (N--) {
		scanf("\n%c %c", &c1, &c2);
		if (c1 == 'C') {
			if (c2 == 'C') { // 平
				cnt2[0][1] += 1;
				cnt2[1][1] += 1;
			}
			else if (c2 == 'J') { // 甲胜，乙负
				++cnt1[0][1];
				++cnt2[0][0];
				++cnt2[1][2];
			}
			else { // c2 == 'B' 甲负，乙胜
				++cnt1[1][0];
				++cnt2[0][2];
				++cnt2[1][0];
			}
		}
		else if (c1 == 'J') {
			if (c2 == 'C') { // 甲负
				++cnt1[1][1];
				++cnt2[0][2];
				++cnt2[1][0];
			}
			else if (c2 == 'J') { // 平
				cnt2[0][1] += 1;
				cnt2[1][1] += 1;
			}
			else { // c2 == 'B' 甲胜
				++cnt1[0][2];
				++cnt2[0][0];
				++cnt2[1][2];
			}
		}
		else { // c1 == 'B'
			if (c2 == 'C') { // 甲胜
				++cnt1[0][0];
				++cnt2[0][0];
				++cnt2[1][2];
			}
			else if (c2 == 'J') { // 甲负
				++cnt1[1][2];
				++cnt2[0][2];
				++cnt2[1][0];
			}
			else { // c2 == 'B' 平
				cnt2[0][1] += 1;
				cnt2[1][1] += 1;
			}
		}
	}

	// 计算甲乙获胜次数最多的手势
	int num_1_id = 0;
	int num_2_id = 0;
	for (int i = 1; i < 3; ++i) {
		if (cnt1[0][i] > cnt1[0][num_1_id]) {
			num_1_id = i;
		}
		if (cnt1[1][i] > cnt1[1][num_1_id]) {
			num_1_id = i;
		}
	}

	printf("%d %d %d\n", cnt2[0][0], cnt2[0][1], cnt2[0][2]);
	printf("%d %d %d\n", cnt2[1][0], cnt2[1][1], cnt2[1][2]);
	printf("%c %c\n", ss[num_1_id], ss[num_2_id]);
}