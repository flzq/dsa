#include <cstdio>
#include <algorithm>
using namespace std;

int matrix[500][500], all_cost[500][500]{ 0 };

class Pat_a1030 {
	int N, M, S, D, INF{510};
	int d[500], c[500], path[500];
	bool visited[500]{ false };
public:
	void pat_a1030() {
		int u, v, dis, cost;
		scanf("%d%d%d%d", &N, &M, &S, &D);
		fill(matrix[0], matrix[0] + 500*500, INF); // 注意这里绝对不能用N*N，否则会无法覆盖所有点，导致样例的matrix[1][2]=0
		fill(d, d + N, INF);
		fill(c, c + N, INF);
		fill(path, path + N, -1);
		for (int i = 0; i < M; ++i) {
			scanf("%d%d%d%d", &u, &v, &dis, &cost);
			matrix[u][v] = dis;
			matrix[v][u] = dis;
			all_cost[u][v] = cost;
			all_cost[v][u] = cost;
		}
		dijkstra(S);
		print(D);
		printf("%d %d", d[D], c[D]);
	}
	void print(int D) {
		if (path[D] == -1) {
			printf("%d ", D);
			return;
		}
		print(path[D]);
		printf("%d ", D);
	}
	void dijkstra(int s) {
		d[s] = 0;
		c[s] = 0;
		for (int i = 0; i < N; ++i) {
			int u = -1, min_dis = INF;
			for (int j = 0; j < N; ++j) {
				if (visited[j] == false && d[j] < min_dis) {
					u = j;
					min_dis = d[j];
				}
			}
			if (u == -1) {
				return;
			}
			visited[u] = true;
			for (int v = 0; v < N; ++v) {
				if (visited[v] == false && matrix[u][v] < INF) {
					if (d[u] + matrix[u][v] < d[v]) {
						d[v] = d[u] + matrix[u][v];
						c[v] = c[u] + all_cost[u][v];
						path[v] = u;
					}
					else if (d[u] + matrix[u][v] == d[v] && c[u] + all_cost[u][v] < c[v]) {
						c[v] = c[u] + all_cost[u][v];
						path[v] = u;
					}
				}
			}
		}
	}
};

//int main() {
//	Pat_a1030 pat_a1030;
//	pat_a1030.pat_a1030();
//	return 0;
//}