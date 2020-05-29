#include <cstdio>
#include <cstring>

struct Node {
	char id[16];
	int h{ 0 }, m{ 0 }, s{ 0 };
	Node() {}
	Node(int h_, int m_, int s_) : h{ h_ }, m{ m_ }, s{ s_ } {}
};

// ���ڱȽ���������
bool less(Node& t1, Node& t2) {
	// t1 �� t2 �磬����true
	if (t1.h != t2.h) {
		return t1.h < t2.h;
	}
	else if (t1.m != t2.m) {
		return t1.m < t2.m;
	}
	else {
		return t1.s < t2.s;
	}

}
// ���ڱȽϽ����ʱ��
bool greater(Node& t1, Node& t2) {
	// t1��t2������true
	if (t1.h != t2.h) {
		return t1.h > t2.h;
	}
	else if (t1.m != t2.m) {
		return t1.m > t2.m;
	}
	else {
		return t1.s > t2.s;
	}
}


void pat_a1006() {
	Node earliest{ 24, 59, 59 }; // ��¼��������
	Node latest{ 0, 0, 0 }; // ��¼�����ߵ�
	Node tmp_early, tmp_later; // ��¼�����ʱ����뿪��ʱ��
	char id[16];
	int M;
	scanf("%d", &M);
	while (M--) {
		scanf("%s %d:%d:%d %d:%d:%d", id, &tmp_early.h, &tmp_early.m, &tmp_early.s, &tmp_later.h, &tmp_later.m, &tmp_later.s);
		if (less(tmp_early, earliest)) {
			earliest = tmp_early;
			strcpy(earliest.id, id);
		}
		if (greater(tmp_later, latest)) {
			latest = tmp_later;
			strcpy(latest.id, id);
		}
	}
	printf("%s %s", earliest.id, latest.id);
}


//int main() {
//	pat_a1006();
//
//	return 0;
//}