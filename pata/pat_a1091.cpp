#include <cstdio>
#include <queue>
using namespace std;

struct Node_pat_a1103 {
	int x, y;
};
int matrix_pat_a1091[1286*60][128];
int inq_pat_a1091[1286 * 60][128]{ false };

bool judge_pat_a1091(int x, int y, int M, int N, int L) {
	if (x < 0 || x > M * L || y < 0 || y > N) {
		return false;
	}
	if (inq_pat_a1091[x][y] == true) {
		return false;
	}
	if (matrix_pat_a1091[x][y] == 0) {
		return false;
	}
	return true;
}

int bfs_pat_a1091(int x, int y, int M, int N, int L) {
	queue<Node_pat_a1103> q;
	Node_pat_a1103 node;
	int res{ 0 };
	int X[8]{ 0, 0, 1, -1, -1, -1, 1, 1 };
	int Y[8]{ 1, -1, 0, 0, -1, 1, -1, 1 };
	node.x = x;
	node.y = y;
	q.push(node);
	++res;
	inq_pat_a1091[x][y] = true;

	while (q.empty() == false) {
		node = q.front();
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int new_x = node.x + X[i];
			int new_y = node.y + Y[i];
			if (judge_pat_a1091(new_x, new_y, M, N, L)) {
				node.x = new_x;
				node.y = new_y;
				q.push(node);
				inq_pat_a1091[new_x][new_y] = true;
				++res;
			}
		}
	}

	return res;
}

void pat_a1091() {
	int M, N, L, T;
	scanf("%d%d%d%d", &M, &N, &L, &T);
	for (int i = 0; i < M * L; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &matrix_pat_a1091[i][j]);
		}
	}
	int cnt{ 0 };

	for (int i = 0; i < M * L; ++i) {
		for (int j = 0; j < N; ++j) {
			if (inq_pat_a1091[i][j] == false && matrix_pat_a1091[i][j] == 1) {
				int res = bfs_pat_a1091(i, j, M, N, L);
				if (res >= T) {
					cnt += res;
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