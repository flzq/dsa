#pragma once
const int cutoff = 3;
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int partion(int* data, int left, int right) {
	int tmp = data[left];
	while (left < right) {
		while (left < right && data[right] > tmp) {
			--right;
		}
		data[left] = data[right];
		while (left < right && data[left] >= tmp) {
			++left;
		}
		data[right] = data[left];
	}
	data[left] = tmp;

	return left;
}
void QSort(int* data, int left, int right) {
	if (left < right) {
		int pivot = partion(data, left, right);
		QSort(data, left, pivot - 1);
		QSort(data, pivot + 1, right);
	}
}
void quick_sort(int* data_, int size_) {
	QSort(data_, 0, size_ - 1);
}
