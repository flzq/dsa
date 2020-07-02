#include <cstdio>
#include <stack>
using std::stack;

struct Node_pat_a1032 {
	int next;
}node_pat_a1032[100010];

void pat_a1032() {
	int first_addr, sec_addr, N, addr, next_addr;
	stack<int> word1, word2;
	char c;
	scanf("%d%d%d", &first_addr, &sec_addr, &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d %c %d", &addr, &c, &next_addr);
		node_pat_a1032[addr].next = next_addr;
	}
	while (first_addr != -1) {
		word1.push(first_addr);
		first_addr = node_pat_a1032[first_addr].next;
	}
	while (sec_addr != -1) {
		word2.push(sec_addr);
		sec_addr = node_pat_a1032[sec_addr].next;
	}
	bool flag = false;
	int common;
	while (word1.empty() == false && word2.empty() == false) {
		if (word1.top() != word2.top()) {
			break;
		}
		common = word1.top();
		word1.pop();
		word2.pop();
		flag = true;
	}
	if (flag == true) {
		printf("%05d", common);
	}
	else {
		printf("-1");
	}
}

//int main() {
//	pat_a1032();
//	return 0;
//}