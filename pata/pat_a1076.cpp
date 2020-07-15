#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node_pat_a1076 {
	int id, level;
	Node_pat_a1076(int id_, int level_) : id{ id_ }, level{level_} {}
};

class Pat_a1076 {
	int N, L, num, id;
	vector<int> adj[1010];
public:
	void pat_a1076() {
		scanf("%d%d", &N, &L);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &num);
			for (int j = 0; j < num; ++j) {
				scanf("%d", &id);
				adj[id].push_back(i);
			}
		}
		scanf("%d", &num);
		for (int i = 0; i < num; ++i) {
			scanf("%d", &id);
			bfs(id, L);
		}
	}
	void bfs(int id, int L) {
		queue<Node_pat_a1076> q;
		bool inq[1010]{ false };
		int cnt{ 0 };
		q.push(Node_pat_a1076(id, 0));
		inq[id] = true;
		while (q.empty() == false) {
			Node_pat_a1076 tmp = q.front();
			q.pop();
			if (tmp.level > L) {
				break;
			}
			++cnt;

			for (int i = 0; i < adj[tmp.id].size(); ++i) {
				int u = adj[tmp.id][i];
				if (inq[u] == false) {
					q.push(Node_pat_a1076(u, tmp.level + 1));
					inq[u] = true;
				}
			}
		}
		printf("%d\n", cnt - 1);
	}
};

//int main() {
//	Pat_a1076 pat_a1076;
//	pat_a1076.pat_a1076();
//	return 0;
//}