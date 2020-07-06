#include <cstdio>
#include <queue>
using namespace std;

struct Node_pat_a1103 {
	int c, x, y;
};
int matrix_pat_a1091[61][1290][130];
int inq_pat_a1091[61][1290][130]{ false };

bool judge_pat_a1091(int c, int x, int y, int M, int N, int L) {
	if (c<0 || c >= L || x < 0 || x >= M || y < 0 || y >= N) {
		return false;
	}
	if (inq_pat_a1091[c][x][y] == true) {
		return false;
	}
	if (matrix_pat_a1091[c][x][y] == 0) {
		return false;
	}
	return true;
}

int bfs_pat_a1091(int c, int x, int y, int M, int N, int L) {
	queue<Node_pat_a1103> q;
	Node_pat_a1103 node;
	int res{ 0 };
	int C[6]{0, 0, 0, 0, 1, -1};
	int X[6]{ 0, 0, 1, -1, 0, 0};
	int Y[6]{ 1, -1, 0, 0, 0, 0};
	node.x = x;
	node.y = y;
	node.c = c;
	q.push(node);
	inq_pat_a1091[c][x][y] = true;

	while (q.empty() == false) {
		node = q.front();
		q.pop();
		++res;
		for (int i = 0; i < 6; ++i) {
			int new_c = node.c + C[i];
			int new_x = node.x + X[i];
			int new_y = node.y + Y[i];
			if (judge_pat_a1091(new_c, new_x, new_y, M, N, L)) {
				node.c = new_c;
				node.x = new_x;
				node.y = new_y;
				q.push(node);
				inq_pat_a1091[new_c][new_x][new_y] = true;
			}
		}
	}

	return res;
}

void pat_a1091() {
	int M, N, L, T;
	scanf("%d%d%d%d", &M, &N, &L, &T);
	for (int k = 0; k < L; ++k) {
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				scanf("%d", &matrix_pat_a1091[k][i][j]);
			}
		}
	}

	int cnt{ 0 };

	for (int k = 0; k < L; ++k) {
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (inq_pat_a1091[k][i][j] == false && matrix_pat_a1091[k][i][j] == 1) {
					int res = bfs_pat_a1091(k, i, j, M, N, L);
					if (res >= T) {
						cnt += res;
					}
				}
			}
		}
	}

	printf("%d", cnt);
}

//int main() {
//	pat_a1091();
//	return 0;
//}