#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int matrix_pat_a1034[2000][2000]{ 0 };

struct Node_pat_a1034 {
	string name;
	int weight;
	Node_pat_a1034(string name_, int weight_) : name{ name_ }, weight{ weight_ } {}
};

bool cmp_pat_a1034(Node_pat_a1034& a, Node_pat_a1034& b) {
	return a.weight > b.weight;
}

class Pat_a1034 {
	int N, K, weight, cnt{ 0 }, id1, id2, sum_weight[2000]{ 0 };
	int cnt_gangs{ 0 };
	bool visited[2000]{ false };
	string name1, name2;
	vector<Node_pat_a1034> vres;
	map<string, int> s2i;
	map<int, string> i2s;
public:

	void pat_a1034() {
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; ++i) {
			cin >> name1 >> name2 >> weight;
			if (s2i.find(name1) == s2i.end()) {
				s2i[name1] = cnt;
				i2s[cnt++] = name1;
			}
			if (s2i.find(name2) == s2i.end()) {
				s2i[name2] = cnt;
				i2s[cnt++] = name2;
			}
			id1 = s2i[name1];
			id2 = s2i[name2];
			matrix_pat_a1034[id1][id2] += weight;
			matrix_pat_a1034[id2][id1] += weight;
			sum_weight[id1] += weight;
			sum_weight[id2] += weight;
		}
		for (int i = 0; i < cnt; ++i) {
			if (visited[i] == false) {
				int total_weight{ 0 };
				vector<Node_pat_a1034> vmem;
				dfs(i, vmem, total_weight);
				total_weight /= 2; // 可能有环，所以重复加了边的权重
				if (vmem.size() > 2 && total_weight > K) {
					++cnt_gangs;
					sort(vmem.begin(), vmem.end(), cmp_pat_a1034);
					vres.push_back(Node_pat_a1034(vmem[0].name, vmem.size()));
				}
			}
		}
		if (cnt_gangs) {
			cout << cnt_gangs << endl;
			for (int i = 0; i < vres.size(); ++i) {
				cout << vres[i].name << " " << vres[i].weight << endl;
			}
		}
		else {
			cout << 0 << endl;
		}

	}
	void dfs(int u, vector<Node_pat_a1034> &vmem, int &total_weight) {
		visited[u] = true;
		vmem.push_back(Node_pat_a1034(i2s[u], sum_weight[u]));
		for (int v = 0; v < cnt; ++v) {
			total_weight += matrix_pat_a1034[u][v]; // 因为可能有环，所以为了加到所有边权，重复加了边的权重
			if (visited[v] == false && matrix_pat_a1034[u][v] > 0) {
				dfs(v, vmem, total_weight);
			}
		}
	}
};



//int main() {
//	Pat_a1034 pat_a1034;
//	pat_a1034.pat_a1034();
//	return 0;
//}