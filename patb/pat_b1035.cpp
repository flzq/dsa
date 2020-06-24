#include <cstdio>

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
	bool flag = true; // ��ʾ�ǹ鲢��������
	for (; step <= N; step*=2) {
		// ��ͷ��ʼ�ҵ����������
		int left = 0;
		int right = (N - 1) < (left + step - 1) ? (N - 1) : (left + step - 1);
		// �ж�[left, right]�����Ƿ�����
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

	int cnt_cout{ 0 }; // ��¼��������ֵĸ���
	if (step > 2) { // ��ʾ�ǹ鲢����
		printf("Merge Sort\n");
		// �ٽ���һ�ι鲢����
		int left = 0;
		int right = left + step - 1;
		while (left < right) {
			int L1 = left;
			int R1 = left + step / 2 - 1;
			int L2 = left + step / 2;
			int R2 = right;
			while (L1 <= R1 && L2 <= R2) {
				if (L1 != 0) {
					printf(" ");
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
				printf("%d", mid_numbers[L1++]);
			}
			while (L2 <= R2) {
				if (cout_black != 0) {
					printf(" ");
					++cout_black;
				}
				printf("%d", mid_numbers[L2++]);
			}
			left += step;
			right = (N - 1) < (right + step) ? (N - 1) : (right + step);
		}
	}
	else {
		// cnt ��¼�����������
		int cnt{ 1 };
		for (int i = 0; i < N-1 && mid_numbers[i]<=mid_numbers[i+1]; ++i) {
			++cnt;
		}
		// ���ǰcnt��
		printf("Insertion Sort\n");
		int i = 0, j = cnt-1;
		while (i <= cnt - 2 && j <= cnt - 1) {
			if (cout_black != 0) {
				printf(" ");
			}
			if (mid_numbers[i] <= mid_numbers[j]) {
				printf("%d", mid_numbers[i++]);
				++cout_black;
			}
			else {
				printf("%d", mid_numbers[j++]);
			}
		}
		while (i <= cnt - 2) {
			if (cout_black != 0) {
				printf(" ");
				++cout_black;
			}
			printf("%d", mid_numbers[i++]);
		}
		while (j <= cnt - 1) {
			if (cout_black != 0) {
				printf(" ");
				++cout_black;
			}
			printf("%d", mid_numbers[j++]);
		}
		i = cnt;
		while (i < N) {
			if (cout_black != 0) {
				printf(" ");
				++cout_black;
			}
			printf("%d", mid_numbers[i++]);
		}
	}
}


int main() {
	pat_b1035();
	return 0;
}