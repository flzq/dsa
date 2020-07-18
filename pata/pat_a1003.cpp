#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXV{ 500 };

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

class Pat_a1003_BellmanFord {
	int N, M, C1, C2, INF{ 1000000000 };
	int num_city_teams[MAXV]{ 0 }, dis[MAXV];
	struct Node {
		int v, weight;
		Node(int v_, int weight_) : v{ v_ }, weight{ weight_ } {}
	};
	vector<Node> Adj[MAXV];
public:
	void pat_a1003() {
		int c1, c2, weight;
		fill(dis, dis + MAXV, INF);
		scanf("%d%d%d%d", &N, &M, &C1, &C2);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &num_city_teams[i]);
		}
		for (int i = 0; i < M; ++i) {
			scanf("%d%d%d", &c1, &c2, &weight);
			Adj[c1].push_back(Node(c2, weight));
			Adj[c2].push_back(Node(c1, weight));
		}
		bellman_ford(C1);
	}
	void bellman_ford(int s) {
		dis[s] = 0;
		int u, v;
		for (int i = 0; i < N - 1; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < Adj[j].size(); ++k) {
					u = j;
					v = Adj[u][k].v;
					if (dis[u] + Adj[u][k].weight < dis[v]) {
						dis[v] = dis[u] + Adj[u][k].weight;
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