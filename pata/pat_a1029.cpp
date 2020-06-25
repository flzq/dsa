#include <cstdio>
#include <algorithm>
using std::sort;

long long numbers[400010];
void pat_a1029() {
	int N1, N2;
	scanf("%d", &N1);
	for (int i = 0; i < N1; ++i) {
		scanf("%lld", &numbers[i]);
	}
	scanf("%d", &N2);
	for (int i = 0; i < N2; ++i) {
		scanf("%lld", &numbers[N1 + i]);
	}
	sort(numbers, numbers + N1 + N2);
	int mid = (N1 + N2 - 1) / 2;
	printf("%lld", numbers[mid]);
}

//int main() {
//	pat_a1029();
//	return 0;
//}