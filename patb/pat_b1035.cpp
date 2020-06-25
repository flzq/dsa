#include <cstdio>
/*
归并排序的中间步骤中,在step==2时,一定有序
因此, step==2时,如果归并排序不是有序,则一定是插入排序,否则是归并排序
*/
void pat_b1035() {
	int N;
	int numbers[100];
	int mid_numbers[100];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &numbers[i]);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%d", &mid_numbers[i]);
	}

	int step{ 2 };
	bool flag = true; // 表示是归并排序序列
	for (; step <= N; step*=2) {
		// 从头开始找到有序的序列
		int left = 0;
		int right = (N - 1) < (left + step - 1) ? (N - 1) : (left + step - 1);
		// 判断[left, right]区域是否有序
		while (left < right) {
			for (int i = left; i < right; ++i) {
				if (mid_numbers[i] > mid_numbers[i + 1]) {
					flag = false;
					break;
				}
			}
			if (flag == false) {
				break;
			}
			left += step;
			right = (N - 1) < (right + step) ? (N - 1) : (right + step);
		}
		if (flag == false) {
			break;
		}
	}

	int cnt_cout{ 0 }; // 记录输出的数字的个数
	if (step > 2) { // 表示是归并排序
		printf("Merge Sort\n");
		// 再进行一次归并排序
		int left = 0;
		int right = left + step - 1;
		while (left < right) {
			int L1 = left;
			int R1 = left + step / 2 - 1;
			int L2 = left + step / 2;
			int R2 = right;
			while (L1 <= R1 && L2 <= R2) {
				if (cnt_cout != 0) {
					printf(" ");
					++cnt_cout;
				}
				if (mid_numbers[L1] <= mid_numbers[L2]) {
					printf("%d", mid_numbers[L1++]);
					++cnt_cout;
				}
				else {
					printf("%d", mid_numbers[L2++]);
					++cnt_cout;
				}
			}
			while (L1 <= R1) {
				if (cnt_cout != 0) {
					printf(" ");
					++cnt_cout;
				}
				printf("%d", mid_numbers[L1++]);
				++cnt_cout;
			}
			while (L2 <= R2) {
				if (cnt_cout != 0) {
					printf(" ");
					++cnt_cout;
				}
				printf("%d", mid_numbers[L2++]);
				++cnt_cout;
			}
			left += step;
			right = (N - 1) < (right + step) ? (N - 1) : (right + step);
		}
	}
	else {
		// cnt 记录了有序的数量
		int cnt{ 1 };
		for (int i = 0; i < N-1 && mid_numbers[i]<=mid_numbers[i+1]; ++i) {
			++cnt;
		}
		// 输出前cnt+1个
		printf("Insertion Sort\n");
		int i = 0, j = cnt;
		while (i <= cnt - 1 && j <= cnt) {
			if (cnt_cout != 0) {
				printf(" ");
			}
			if (mid_numbers[i] <= mid_numbers[j]) {
				printf("%d", mid_numbers[i++]);
				++cnt_cout;
			}
			else {
				printf("%d", mid_numbers[j++]);
				++cnt_cout;
			}
		}
		while (i <= cnt - 1) {
			if (cnt_cout != 0) {
				printf(" ");
				++cnt_cout;
			}
			printf("%d", mid_numbers[i++]);
			++cnt_cout;
		}
		while (j <= cnt) {
			if (cnt_cout != 0) {
				printf(" ");
				++cnt_cout;
			}
			printf("%d", mid_numbers[j++]);
			++cnt_cout;
		}
		i = cnt+1;
		while (i < N) {
			if (cnt_cout != 0) {
				printf(" ");
				++cnt_cout;
			}
			printf("%d", mid_numbers[i++]);
			++cnt_cout;
		}
	}
}


//int main() {
//	pat_b1035();
//	return 0;
//}