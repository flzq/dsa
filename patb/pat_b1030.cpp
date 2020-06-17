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
		// �ҵ�һ����M��ʹ���������һ������M<=mp
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
		// ����[i, left-1]�����ø���
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