#pragma once

/*
	�鲢����
*/
class MergeSort {
private:
	int* data{ nullptr };
	int* tmp_data{ nullptr }; // ���ڴ洢��ʱ�ź����ֵ
	int size{ 0 };
	// �ϲ�������������
	void merge(int left_begin, int left_end, int right_end) {
		/*
			[left_begin, left_end]����һ������ķ�Χ
			[rigth_begin, right_end]���ڶ�������ķ�Χ
		*/
		int right_begin = left_end + 1;
		int begin = left_begin; // ��������ʱ�����д洢����������
		int begin2 = left_begin; // ���ڸ��ƻ�ԭ����
		while ((left_begin <= left_end) && (right_begin <= right_end)) {
			if (data[left_begin] <= data[right_begin]) { // Ϊ�˱���������ȶ��ԣ�Ҫ�еȺ�
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
		// ����ʱ���ݸ�ֵ��ԭ����
		for (; begin2 <= right_end; ++begin2) {
			data[begin2] = tmp_data[begin2];
		}
	}
	void msort(int begin, int end) {
		/*
			begin��end���������������ķ�Χ��[begin, end]
		*/
		// ��ֻ��һ������һ��Ԫ��������
		if (begin >= end) {
			return;
		}
		int mid = (begin + end) / 2;
		// �֣������������зֱ�����
		msort(begin, mid);
		msort(mid + 1, end);
		// ���������������ϲ�
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
