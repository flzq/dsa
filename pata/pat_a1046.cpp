#include <cstdio>

void pat_a1046() {
	int N, M, weight{ 0 };
	int src, end;
	scanf("%d", &N);
	int* dis = new int[N + 1]; // dis[i]��ʾ����1->i-th����·�̣�dis[0]��ʾ��������·��
	dis[1] = 0; // dis[1]==0 ��ʾ��1->1�ľ���Ϊ0
	for (int i = 2; i <= N; ++i) {
		scanf("%d", &weight);
		dis[i] = dis[i - 1] + weight;
	}
	scanf("%d", &weight);
	dis[0] = dis[N] + weight; // ��ʾ�������ĳ���
	scanf("%d", &M);
	while (M--) {
		scanf("%d%d", &src, &end);
		// �����⣬����һ����·������·�߿����ǣ�src->end��Ҳ�����ǣ�end->src��
		// �������������룬Ȼ�������С��
		// ��С��·�ڵ����·�ڼ�����룬�෴�ķ������ܾ���������ɣ��ܾ���洢��dis[1]��
		int dis1, dis2;
		if (src < end) {
			dis1 = dis[end] - dis[src];
			dis2 = dis[0] - dis1;
		}
		else { // src > end��
			dis1 = dis[src] - dis[end];
			dis2 = dis[0] - dis1;
		}
		printf("%d\n", (dis1 > dis2 ? dis2 : dis1));
	}
}