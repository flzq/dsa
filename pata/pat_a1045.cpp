#include <cstdio>

class Pat_a1045 {
	int N, M, L, favorite[200], stripe[10000];
public:
	void pat_a1045() {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; ++i) {
			scanf("%d", &favorite[i]);
		}
		scanf("%d", &L);
		for (int i = 0; i < L; ++i) {
			scanf("%d", &stripe[i]);
		}

	}
};

//int main() {
//	Pat_a1045 pat_a1045;
//	pat_a1045.pat_a1045();
//	return 0;
//}