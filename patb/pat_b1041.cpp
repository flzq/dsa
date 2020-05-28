#include <cstdio>

struct Node {
	const char* str;
	int exam_id;
	Node() {}
	Node(const char* str_, int exam_id_) : str{ str_ }, exam_id{ exam_id_ }{

	}
};

void pat_b1041() {
	Node nodes[1010]; // 1 <= N <= 1000
	char str[1010][17];
	int N;
	int id, exam_id;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s%d%d", str[i], &id, &exam_id);
		nodes[id].str = str[i];
		nodes[id].exam_id = exam_id;
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &id);
		printf("%s %d\n", nodes[id].str, nodes[id].exam_id);
	}
}


int main() {
	pat_b1041();

	return 0;
}