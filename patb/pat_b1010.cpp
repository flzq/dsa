#include <cstdio>
#include <vector>
using std::vector;

struct Node {
	int a, b; // a存储系数，b存储指数
	Node(int a_, int b_) : a{ a_ }, b{ b_ }{}
};

void pat_b1010() {
	int a, b; // a：系数；b：指数
	vector<Node> nodes;
	while (scanf("%d%d", &a, &b) != EOF) {
		nodes.emplace_back(a, b);
	}
	for (auto& x : nodes) {
		if (x.b == 0) {
			x.a = 0;
			x.b = 0;
		}
		else {
			x.a = x.a * x.b;
			--x.b;
		}
	}
	if (nodes.size() == 1) { // 处理一项的以及零多项式
		printf("%d %d", nodes[0].a, nodes[0].b);
	}
	else {
		for (int i = 0; i < nodes.size() - 1; ++i) {
			if (i != nodes.size() - 2) {
				printf("%d %d ", nodes[i].a, nodes[i].b);
			}
			else {
				printf("%d %d", nodes[i].a, nodes[i].b);
			}
		}
	}
}

