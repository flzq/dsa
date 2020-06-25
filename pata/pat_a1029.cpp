#include <cstdio>
#include <algorithm>
using std::sort;

//long numbers[200000];
//long numbers2[200000];
//
//void pat_a1029() {
//
//	int N, N2, index1{ 0 }, index2{ 0 }, cnt{ 0 }; // cnt记录顺序数字个数,从0开始
//	bool flag = false; // 已经输出了
//	scanf("%d", &N);
//	for (int i = 0; i < N; ++i) {
//		scanf("%d", &numbers[i]);
//	}
//	scanf("%d", &N2);
//	int mid = (N + N2 - 1) / 2;
//	for (int i = 0; i < N2; ++i) {
//		scanf("%d", &numbers2[i]);
//	}
//	while (index1 < N && index2 < N2) {
//		if (numbers[index1] <= numbers2[index2]) {
//			if (mid == cnt) {
//				printf("%d", numbers[index1]);
//				flag = true;
//				break;
//			}
//			++index1;
//			++cnt;
//		}
//		else {
//			if (mid == cnt) {
//				printf("%d", numbers[index2]);
//				flag = true;
//				break;
//			}
//			++index2;
//			++cnt;
//		}
//	}
//	while (flag == false && index1 < N) {
//		if (mid == cnt) {
//			printf("%d", numbers[index1]);
//			flag = true;
//			break;
//		}
//		++index1;
//		++cnt;
//	}
//	while (flag == false && index2 < N2) {
//		if (mid == cnt) {
//			printf("%d", numbers[index2]);
//			flag = true;
//			break;
//		}
//		++index2;
//		++cnt;
//	}
//}

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