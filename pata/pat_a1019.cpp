#include <cstdio>
#include <vector>
using std::vector;

void pat_a1019() {
	int N, b, cnt{ 0 };
	bool is_par = true;
	vector<int> digs;
	scanf("%d%d", &N, &b);
	do {
		digs.push_back(N % b);
		N = N / b;
	} while (N != 0);
	cnt = digs.size();
	for (int i = 0, j = cnt - 1 ; i < j && is_par == true; ++i, --j) {
		if (digs[i] != digs[j]) {
			is_par = false;
		}
	}
	if (is_par) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	for (int i = cnt - 1; i >= 0; --i) {
		printf("%d", digs[i]);
		if (i != 0) {
			printf(" ");
		}
	}
}

//int main() {
//	pat_a1019();
//}