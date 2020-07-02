#include <cstdio>
#include <algorithm>
using namespace std;

struct Node_pat_a1052 {
	int addr, data{ 100010 }, next;
	int ordered{ -1 };
}node_pat_a1052[100010];

bool cmp_pat_a1052(Node_pat_a1052& a, Node_pat_a1052& b) {
	// 可能有无效的节点
	if (a.ordered == -1 || b.ordered == -1) {
		return a.ordered > b.ordered;
	}
	else {
		return a.data < b.data;
	}

}

void pat_a1052() {
	int N, head_addr, curr_addr, data, next_addr, cnt{ 0 };
	scanf("%d%d", &N, &head_addr);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d%d", &curr_addr, &data, &next_addr);
		node_pat_a1052[curr_addr].addr = curr_addr;
		node_pat_a1052[curr_addr].data = data;
		node_pat_a1052[curr_addr].next = next_addr;
	}
	// 统计有效节点
	while (head_addr != -1) {
		node_pat_a1052[head_addr].ordered = cnt++;
		head_addr = node_pat_a1052[head_addr].next;
	}
	// 排序
	sort(node_pat_a1052, node_pat_a1052 + 100010, cmp_pat_a1052);
	// 都为无效节点
	if (cnt == 0) {
		printf("0 -1");
	}
	else {
		printf("%d %05d\n", cnt, node_pat_a1052[0].addr);
		for (int i = 0; i < cnt; ++i) {
			if (i != cnt - 1) {
				printf("%05d %d %05d\n", node_pat_a1052[i].addr, node_pat_a1052[i].data, node_pat_a1052[i + 1].addr);
			}
			else {
				printf("%05d %d -1\n", node_pat_a1052[i].addr, node_pat_a1052[i].data);
			}
		}
	}

}

//int main() {
//	pat_a1052();
//	return 0;
//}