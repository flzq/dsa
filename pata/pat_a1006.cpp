#include <cstdio>
#include <cstring>

struct Node {
	char id[16];
	int h{ 0 }, m{ 0 }, s{ 0 };
	Node() {}
	Node(int h_, int m_, int s_) : h{ h_ }, m{ m_ }, s{ s_ } {}
};

// 用于比较最早来的
bool less(Node& t1, Node& t2) {
	// t1 比 t2 早，返回true
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
// 用于比较较晚的时间
bool greater(Node& t1, Node& t2) {
	// t1比t2晚，返回true
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
	Node earliest{ 24, 59, 59 }; // 记录最早来的
	Node latest{ 0, 0, 0 }; // 记录最晚走的
	Node tmp_early, tmp_later; // 记录进入的时间和离开的时间
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