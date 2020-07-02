#include <cstdio>
#include <stack>
using std::stack;

struct Node_pat_b1025 {
	int data;
	int next;
}node_pat_b1025[100010];

void pat_b1025() {
	int addr, N, K, next_addr, data, first_addr, head_addr;
	scanf("%d%d%d", &first_addr, &N, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d%d", &addr, &data, &next_addr);
		node_pat_b1025[addr].data = data;
		node_pat_b1025[addr].next = next_addr;
	}
	int t = N / K;
	for (int i = 0; i < t; ++i) {
		stack<int> st;
		for (int j = 0; j < K; ++j) {
			st.push(first_addr);
			first_addr = node_pat_b1025[first_addr].next;
		}
		if (i == 0) {
			head_addr = st.top();
		}
		int sub_first_addr = st.top();
		int sub_next_addr;
		st.pop();
		while (st.empty() == false) {
			sub_next_addr = st.top();
			st.pop();
			node_pat_b1025[sub_first_addr].next = sub_next_addr;
			sub_first_addr = sub_next_addr;
		}
		node_pat_b1025[sub_first_addr].next = first_addr;
	}
	for (int i = 0; i < N; ++i) {
		if (head_addr == -1) { // 考虑可能存在无效节点
			break;
		}
		else {
			if (node_pat_b1025[head_addr].next == -1) {
				printf("%05d %d %d\n", head_addr, node_pat_b1025[head_addr].data, node_pat_b1025[head_addr].next);
			}
			else {
				printf("%05d %d %05d\n", head_addr, node_pat_b1025[head_addr].data, node_pat_b1025[head_addr].next);
			}

			head_addr = node_pat_b1025[head_addr].next;
		}

	}
}

//int main() {
//	pat_b1025();
//	return 0;
//}