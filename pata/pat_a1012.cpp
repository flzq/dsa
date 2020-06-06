#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
using std::map;
using std::string;
using std::sort;

struct Stu_pat_a1012 {
	string id;
	int rank_A, rank_C, rank_M, rank_E;
	char course; // 用于比较的分数: A > C > M > E
	double C, M, E, A;
	Stu_pat_a1012() {
		id.resize(8);
	}
}stu[2000];

bool cmp_A(Stu_pat_a1012& a, Stu_pat_a1012& b) {
	return a.A > b.A;
}
bool cmp_C(Stu_pat_a1012& a, Stu_pat_a1012& b) {
	return a.C > b.C;
}
bool cmp_M(Stu_pat_a1012& a, Stu_pat_a1012& b) {
	return a.M > b.M;
}
bool cmp_E(Stu_pat_a1012& a, Stu_pat_a1012& b) {
	return a.E > b.E;
}

void pat_a1012() {
	// 对所有分数都分别进行排序
	// 输出每个人最好的排序(有相同排序的,按照科目优先级输出)
	int N, M;
	string id;
	map<string, int> m;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%s %lf %lf %lf", &stu[i].id[0], &stu[i].C, &stu[i].M, &stu[i].E);
		stu[i].A = (stu[i].C + stu[i].M + stu[i].E) / 3;
		m[stu[i].id] = i;
	}
	// 按照优先级排序
	// 按照A分数排序
	sort(stu, stu + N, cmp_A);
	stu[0].rank_A = 1;
	for (int i = 1; i < N; ++i) {
		if (stu[i].A != stu[i - 1].A) {
			stu[i].rank_A = i + 1;
		}
		else {
			stu[i].rank_A = stu[i - 1].rank_A;
		}
	}
	// 按照C分数排序
	sort(stu, stu + N, cmp_C);
	stu[0].rank_C = 1;
	for (int i = 1; i < N; ++i) {
		if (stu[i].C != stu[i - 1].C) {
			stu[i].rank_C = i + 1;
		}
		else {
			stu[i].rank_C = stu[i - 1].rank_C;
		}
	}
	// 按照M分数排序
	sort(stu, stu + N, cmp_M);
	stu[0].rank_M = 1;
	for (int i = 1; i < N; ++i) {
		if (stu[i].M != stu[i - 1].M) {
			stu[i].rank_M = i + 1;
		}
		else {
			stu[i].rank_M = stu[i - 1].rank_M;
		}
	}
	// 按照E分数排序
	sort(stu, stu + N, cmp_E);
	stu[0].rank_E = 1;
	for (int i = 1; i < N; ++i) {
		if (stu[i].E != stu[i - 1].E) {
			stu[i].rank_E = i + 1;
		}
		else {
			stu[i].rank_E = stu[i - 1].rank_E;
		}
	}


	// 由于stu重新排序了，所以重新调整 m 中stu数组的下标
	for (int i = 0; i < N; ++i) {
		m[stu[i].id] = i;
	}

	id.resize(8);
	for (int i = 0; i < M; ++i) {
		scanf("%s", &id[0]);
		// 找到
		if (m.find(id) == m.end()) {
			printf("N/A\n");
		}
		else {
			int index = m[id];
			if (stu[index].rank_A <= stu[index].rank_C && stu[index].rank_A <= stu[index].rank_M && stu[index].rank_A <= stu[index].rank_E) {
				// A
				printf("%d %c\n", stu[index].rank_A, 'A');
			}
			else if (stu[index].rank_C <= stu[index].rank_M && stu[index].rank_C <= stu[index].rank_E) {
				// C
				printf("%d %c\n", stu[index].rank_C, 'C');
			}
			else if (stu[index].rank_M <= stu[index].rank_E) {
				// M
				printf("%d %c\n", stu[index].rank_M, 'M');
			}
			else {
				// E
				printf("%d %c\n", stu[index].rank_E, 'E');

			}
		}
	}
}

//int main() {
//	pat_a1012();
//
//	return 0;
//}