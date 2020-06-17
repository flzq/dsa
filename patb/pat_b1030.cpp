#include <cstdio>
#include <algorithm>
using std::sort;

void pat_b1030() {
	int N, p, max{ -1 };
	int numbers[100000];
	scanf("%d%d", &N, &p);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &numbers[i]);
	}
	sort(numbers, numbers + N);
	for (int i = 0; i < N; ++i) {
		int mP = numbers[i] * p;
		// 找到一个数M，使得它是最后一个满足M<=mp
		int left = i, right = N, mid;
		while (left < right) {
			mid = (left + right) / 2;
			if (numbers[mid] > mP) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		// 计算[i, left-1]中数得个数
		if (left - i > max) {
			max = left - i;
		}

	}
	printf("%d", max);
}

//int main() {
//	pat_b1030();
//	return 0;
//}