#pragma once

/*
	归并排序：
*/
class MergeSort {
private:
	int* data{ nullptr };
	int* tmp_data{ nullptr }; // 用于存储临时排好序的值
	int size{ 0 };
	// 合并两个有序数组
	void merge(int left_begin, int left_end, int right_end) {
		/*
			[left_begin, left_end]：第一个数组的范围
			[rigth_begin, right_end]：第二个数组的范围
		*/
		int right_begin = left_end + 1;
		int begin = left_begin; // 用于在临时数组中存储变量的索引
		int begin2 = left_begin; // 用于复制回原数组
		while ((left_begin <= left_end) && (right_begin <= right_end)) {
			if (data[left_begin] <= data[right_begin]) { // 为了保持排序的稳定性，要有等号
				tmp_data[begin++] = data[left_begin++];
			}
			else {
				tmp_data[begin++] = data[right_begin++];
			}
		}
		while (left_begin <= left_end) {
			tmp_data[begin++] = data[left_begin++];
		}
		while (right_begin <= right_end) {
			tmp_data[begin++] = data[right_begin++];
		}
		// 将临时数据赋值回原数组
		for (; begin2 <= right_end; ++begin2) {
			data[begin2] = tmp_data[begin2];
		}
	}
	void msort(int begin, int end) {
		/*
			begin、end：对数组进行排序的范围，[begin, end]
		*/
		// 若只有一个，则一个元素有序了
		if (begin >= end) {
			return;
		}
		int mid = (begin + end) / 2;
		// 分：对两个子序列分别排序
		msort(begin, mid);
		msort(mid + 1, end);
		// 将两个有序的数组合并
		merge(begin, mid, end);

		std::cout << "mergsort: ";
		print();
	}
public:
	MergeSort(int* data_, int size_) : data{ data_ }, size{ size_ } {
		tmp_data = new int[size];
	}
	~MergeSort() {
		delete[] tmp_data;
	}

	void merge_sort() {
		msort(0, size - 1);
	}
	void print() {
		for (int i = 0; i < size; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};
