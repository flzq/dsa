#include <cstdio>
#include <algorithm>
using namespace std;

void insertion_sort_pat_a1098(int* part_sorted, int start, int end) {
	if (start < end) {
		int i = start + 1;
		while (i > 1) {
			if (part_sorted[i] < part_sorted[i - 1]) {
				swap(part_sorted[i], part_sorted[i - 1]);
				i = i - 1;
			}
			else {
				break;
			}
		}
	}
}

void down_adjust_pat_a1098(int* part_sorted, int n) {
	int parent = 1, child = 2;
	while (child <= n) {
		if (child + 1 <= n && part_sorted[child] < part_sorted[child + 1]) {
			child = child + 1;
		}
		if (part_sorted[child] > part_sorted[parent]) {
			swap(part_sorted[child], part_sorted[parent]);
			parent = child;
			child = 2 * parent;
		}
		else {
			break;
		}
	}
}

void heap_sort_pat_a1098(int* part_sorted, int len) {
	if (len > 1) {
		swap(part_sorted[1], part_sorted[len]);
		down_adjust_pat_a1098(part_sorted, len-1);
	}
}

void pat_a1098() {
	int N, origion[110], part_sorted[110];
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &origion[i]);
	}
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &part_sorted[i]);
	}
	if (part_sorted[1] < part_sorted[2]) { // Insertion Sort
		printf("Insertion Sort\n");
		int len{ 1 };
		while (part_sorted[len] < part_sorted[len + 1]) {
			++len;
		}
		insertion_sort_pat_a1098(part_sorted, len, N);
	}
	else { // Heap Sort
		printf("Heap Sort\n");
		int len{ N };
		while (part_sorted[1] < part_sorted[len]) {
			--len;
		}
		heap_sort_pat_a1098(part_sorted, len);
	}
	for (int i = 1; i <= N; ++i) {
		printf("%d", part_sorted[i]);
		if (i < N) {
			printf(" ");
		}
	}
}

//int main() {
//	pat_a1098();
//	return 0;
//}