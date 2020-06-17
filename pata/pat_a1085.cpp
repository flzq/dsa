#include <cstdio>
#include <algorithm>
using std::sort;

void pat_b1030() {
	// ��pat_b1030һ��
	// ע��: ���Ե�5���ʹ��int,��õ�������(��Ϊp<=1e9),����Ҫʹ��long long
	long N, p;
	int max{ -1 };
	long numbers[100000];
	scanf("%d%d", &N, &p);
	for (int i = 0; i < N; ++i) {
		scanf("%lld", &numbers[i]);
	}
	sort(numbers, numbers + N);
	for (int i = 0; i < N; ++i) {
		long long mP = numbers[i] * p;
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