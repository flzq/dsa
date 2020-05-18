#pragma once
const int cutoff = 3;
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int medianPivot(int* data, int left, int right) {
	int mid = (left + right) / 2;
	if (data[left] > data[mid]) swap(&data[left], &data[mid]);
	if (data[left] > data[right]) swap(&data[left], &data[right]);
	if (data[mid] > data[right]) swap(&data[mid], &data[right]);
	swap(&data[mid], &data[right - 1]);
	return data[right - 1];
}
void QSort(int* data, int left, int right) {
	int pivot;
	if (right - left < cutoff) {

	}
	else {
		pivot = medianPivot(data, left, right);
		int i, j;
		i = left + 1;
		j = right - 2;
		while (1) {
			while (data[i] < pivot) i++;
			while (data[j] > pivot) j--;
			if (i < j) swap(&data[i], &data[j]);
			else break;
		}
	}
}
void quick_sort(int* data_, int size_) {
	QSort(data_, 0, size_ - 1);
}
