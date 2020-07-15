#include <cstdio>
#include <algorithm>
using namespace std;

class Pat_a1003 {
	int N, M, C1, C2, id1, id2, weight, INF{ 1000000000 };
	int matrix[500][500]{ 0 };
	int num_team[500]{ 0 };
	int dist[500];
	int total_team[500]{ 0 };
	int num_shortest[500]{ 0 };
	bool visited[500]{ false };
public:
	void pat_a1003() {
		scanf("%d%d%d%d", &N, &M, &C1, &C2);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &num_team[i]);
		}
		fill(matrix[0], matrix[0] + 500 * 500, INF);
		for (int i = 0; i < M; ++i) {
			scanf("%d%d%d", &id1, &id2, &weight);
			matrix[id1][id2] = weight;
			matrix[id2][id1] = weight;
		}
		dijkstra(C1);
		printf("%d %d", num_shortest[C2], total_team[C2]);
	}
	void dijkstra(int s) {
		fill(dist, dist + N, INF);
		dist[s] = 0;
		num_shortest[s] = 1;
		total_team[s] = num_team[s];
		for (int i = 0; i < N; ++i) {
			int u = -1, min_dist = INF;
			for (int j = 0; j < N; ++j) {
				if (visited[j] == false && dist[j] < min_dist) {
					u = j;
					min_dist = dist[j];
				}

			}
			if (u == -1) {
				return;
			}
			visited[u] = true;
			for (int v = 0; v < N; ++v) {
				if (visited[v] == false && matrix[u][v] < INF) {
					if (dist[u] + matrix[u][v] < dist[v]) {
						dist[v] = dist[u] + matrix[u][v];
						total_team[v] = total_team[u] + num_team[v];
						num_shortest[v] = num_shortest[u];
					}
					else if (dist[u] + matrix[u][v] == dist[v]) {
						if (total_team[u] + num_team[v] > total_team[v]) {
							total_team[v] = total_team[u] + num_team[v];
						}
						num_shortest[v] += num_shortest[u];
					}
				}
			}
		}
	}
};

//int main() {
//	Pat_a1003 pat_a1003;
//	pat_a1003.pat_a1003();
//	return 0;
//}