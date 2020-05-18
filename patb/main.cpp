#define _CRT_SECURE_NO_WARNINGS

/*
	���鼯
	�±��1��ʼ
	���ڵ�ĸ��ڵ�Ϊ�������Ҿ���ֵΪ���Ĵ�С
	���ڵ�û�и��ڵ㣬��˸��ڵ�ĸ��ڵ�<0
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

template <typename T>
class DisjointSet {
public:
	T* data{ nullptr };
	int* parent{ nullptr };
	int size{ 0 }; // ��������Ԫ��
	int capacity{ 0 }; // ���ϴ�С
	std::map<T, int> m; // ���ڴ洢<data, index>���ݣ������ԣ�dataΪ����indexΪֵ

public:
	DisjointSet(int capacity_);
	~DisjointSet();
	// ����Ԫ��
	bool insert(T x);
	// ��ӡ
	void print();
	// �ҵ���ӦԪ�������ĸ����ϣ�����Ԫ�ظ��ڵ��±�
	int find(T x);
	// ����Ԫ�صļ����󲢼�
	void union_set(T x, T y);
};

// ����Ԫ�صļ����󲢼�
template <typename T>
void DisjointSet<T>::union_set(T x, T y) {
	int rx = find(x); // ��x���ϸ��ڵ��±�
	int ry = find(y); // ��y���ϸ��ڵ��±�
	if (rx == 0 || ry == 0) { // ����ڵ㲻����
		return;
	}
	if (rx == ry) { // λ��ͬһ������
		return;
	}
	// ʹ��·��ѹ����С����������
	if (parent[rx] < parent[ry]) { // ���ڵ�parentΪ����������ֵΪ���Ĵ�С
		parent[rx] += parent[ry];
		parent[ry] = rx;
	}
	else {
		parent[ry] += parent[rx];
		parent[rx] = ry;
	}
}

// �ҵ�Ԫ�ؼ���
template <typename T>
int DisjointSet<T>::find(T x) {
	typename std::map<T, int>::iterator it = m.find(x);
	// �ڵ��±��1��ʼ��0λ�ò���Ԫ��
	if (it == m.end()) {
		return 0;
	}

	int root = it->second; // ��¼Ԫ��x���ڵ��±�
	while (parent[root] > 0) {
		root = parent[root];
	}

	// ·��ѹ��
	for (int tmp, i = m[x]; i != root; i = tmp) {
		tmp = parent[i];
		parent[i] = root;
	}

	return root;
}
// ����Ԫ��
template <typename T>
bool DisjointSet<T>::insert(T x) {
	if (size == capacity) {
		return false;
	}
	data[++size] = x;
	parent[size] = -1;
	m[x] = size; // �洢<data, index>�ԣ�������Ҷ�ӦԪ�ص��±�
}

// ��ӡԪ��
template <typename T>
void DisjointSet<T>::print() {
	// ��ӡ�±�
	for (int i = 1; i <= size; ++i) {
		std::cout << i << '\t';
	}
	std::cout << std::endl;
	// ��ӡ���ڵ�
	for (int i = 1; i <= size; ++i) {
		std::cout << parent[i] << '\t';
	}
	std::cout << std::endl;
	// ��ӡֵ
	for (int i = 1; i <= size; ++i) {
		std::cout << data[i] << '\t';
	}
	std::cout << std::endl;
}

// ���캯��
template <typename T>
DisjointSet<T>::DisjointSet(int capacity_) : capacity{ capacity_ }, size{ 0 } {
	data = new T[capacity_ + 1]; // �±��1��ʼ
	parent = new int[capacity_ + 1]; // �±��1��ʼ
}
// ��������
template <typename T>
DisjointSet<T>::~DisjointSet() {
	delete[] data;
	delete[] parent;
}

int main() {
	int M, N;
	string name1, name2;
	cin >> N;
	DisjointSet<string> ds{ N };

	for (int i = 0; i < N; ++i) {
		cin >> name1;
		ds.insert(name1);
	}
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> name1 >> name2;
		ds.union_set(name1, name2);
	}
	ds.print();
	cout << endl;
	// ͳ���м���ѧУ
	int num_schools{ 0 };
	int max_stu{ 0 }; // ����
	int max_id{ 0 };
	for (int i = 1; i <= N; ++i) {
		if (ds.parent[i] < 0) {
			++num_schools;
			if (ds.parent[i] < max_stu) {
				max_stu = ds.parent[i];
				max_id = i;
			}
		}
	}
	// ��ӡѧУ����
	cout << num_schools << endl;
	// ��ӡ�������ѧУ��ѧ������
	for (int i = 1, id; i <= N; ++i) {
		id = ds.find(ds.data[i]);
		if (id == max_id) {
			cout << ds.data[i] << " ";
		}
	}
	cout << endl;



	return 0;
}

