#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;

struct Stu_pat_a1028 {
	int id;
	char name[9];
	int score;
}stu[100000];

bool cmp_1(Stu_pat_a1028& a, Stu_pat_a1028& b) {
	// compare id
	return a.id < b.id;
}
bool cmp_2(Stu_pat_a1028& a, Stu_pat_a1028& b) {
	// compare name and id
	if (strcmp(a.name, b.name) != 0) {
		return strcmp(a.name, b.name) < 0;
	}
	else {
		return cmp_1(a, b);
	}
}
bool cmp_3(Stu_pat_a1028& a, Stu_pat_a1028& b) {
	// compare score and id
	if (a.score != b.score) {
		return a.score < b.score;
	}
	else {
		return cmp_1(a, b);
	}
}

void pat_a1028() {
	int N, C;
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; ++i) {
		 scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].score);
	}
	if (C == 1) {
		sort(stu, stu + N, cmp_1);
	}
	else if (C == 2) {
		sort(stu, stu + N, cmp_2);
	}
	else {
		sort(stu, stu + N, cmp_3);
	}
	for (int i = 0; i < N; ++i) {
		 printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
	}
}


//int main() {
//	pat_a1028();
//
//	return 0;
//}