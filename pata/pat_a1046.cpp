#include <cstdio>

void pat_a1046() {
	int N, M, weight{ 0 };
	int src, end;
	scanf("%d", &N);
	int* dis = new int[N + 1]; // dis[i]表示：从1->i-th的总路程；dis[0]表示整个环的路程
	dis[1] = 0; // dis[1]==0 表示从1->1的距离为0
	for (int i = 2; i <= N; ++i) {
		scanf("%d", &weight);
		dis[i] = dis[i - 1] + weight;
	}
	scanf("%d", &weight);
	dis[0] = dis[N] + weight; // 表示整个环的长度
	scanf("%d", &M);
	while (M--) {
		scanf("%d%d", &src, &end);
		// 由题意，这是一个环路，所以路线可以是：src->end，也可以是：end->src；
		// 计算这两个距离，然后输出较小的
		// 从小的路口到大的路口计算距离，相反的方向用总距离相减即可；总距离存储在dis[1]中
		int dis1, dis2;
		if (src < end) {
			dis1 = dis[end] - dis[src];
			dis2 = dis[0] - dis1;
		}
		else { // src > end，
			dis1 = dis[src] - dis[end];
			dis2 = dis[0] - dis1;
		}
		printf("%d\n", (dis1 > dis2 ? dis2 : dis1));
	}
}