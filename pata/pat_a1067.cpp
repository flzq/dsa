#include <cstdio>

void pat_a1067() {
	int N; // 记录除0以外无序的个数
	int k{ 1 }; // 从1开始枚举无序数的下标, 防止使用循环超时, 当k==N时表示所有数都有序了
	int num[100000];
	int inx[100000]; // 数子位置的索引
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &num[i]);
		inx[num[i]] = i;
		if (num[i] != i && i!=0) {
		}
	}
	int cnt{ 0 }; // 记录swap的次数
	while (k < N) { // 从1开始枚举无序数的下标, 防止使用循环超时, 当k==N时表示所有数都有序了
		if (inx[0] != 0) { // 每次交换, 有一个数字都有序
			// printf("(%d, %d) ", 0, inx[0]); // 打印一次转换swap(0, *)
			int index = inx[0];
			int tmp = inx[0];
			inx[0] = inx[index];
			inx[index] = tmp;
			++cnt;
		}
		else {
			// 判断全部数字有没有排好
			// 使用循环找到没有排好的数字, 导致测试点1, 2超时
			// 因此使用 k 从1开始枚举无序数的下标, 防止使用循环超时
			//for (int i = 1; i < N; ++i) {
			//	if (inx[i] != i) {
			//		inx[0] = inx[i];
			//		inx[i] = 0;
			//		flag = false;
			//		++cnt;
			//		break;
			//	}
			//}
			//if (flag) {
			//	break;
			//}
			while (k < N) {
				if (inx[k] != k) {
					inx[0] = inx[k];
					inx[k] = 0;
					++cnt;
					break;
				}
				++k;
			}
		}
	}
	printf("%d", cnt);
}


//int main() {
//	pat_a1067();
//
//	return 0;
//}