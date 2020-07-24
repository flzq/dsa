#include <cstdio>
#include <algorithm>
using namespace std;

class Pat_a1068 {
	int N, M, coins[10010]{ 0 };
public:
	void pat_a1068() {
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &coins[i]);
		}
		sort(coins, coins + N + 1);

	}
};

//int main() {
//	Pat_a1068 pat_a1068;
//	pat_a1068.pat_a1068();
//	return 0;
//}