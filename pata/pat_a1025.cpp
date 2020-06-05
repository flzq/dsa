#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;

struct Stu{
	char reg_num[14];
	int score;
	int final_rank, local_rank, local;
}stu[30000];

bool cmp(Stu& a, Stu& b) {
	if (a.score != b.score) {
		return a.score > b.score;
	}
	else {
		return strcmp(a.reg_num, b.reg_num) < 0;
	}
}

void pat_a1025() {
	int N, K;
	int num_testees{ 0 };
	scanf("%d", &N);
	// 读取考生信息
	for (int i = 0; i < N; ++i) {
		scanf("%d", &K);
		for (int j = 0; j < K; ++j) {
			scanf("%s %d", stu[num_testees].reg_num, &stu[num_testees].score);
			stu[num_testees].local = i + 1;
			++num_testees;
		}
		// 先对每个地区学生分数进行排序
		sort(stu + num_testees - K, stu + num_testees, cmp);
		// 对各地区学生排名
		stu[num_testees - K].local_rank = 1;
		for (int j = num_testees - K + 1; j < num_testees; ++j) {
			if (stu[j].score != stu[j - 1].score) {
				stu[j].local_rank = j - (num_testees - K) + 1;
			}
			else {
				stu[j].local_rank = stu[j - 1].local_rank;
			}
		}
	}
	// 对所有学生分数进行排序
	sort(stu, stu + num_testees, cmp);
	// 对所有学生排名
	stu[0].final_rank = 1;
	for (int i = 1; i < num_testees; ++i) {
		if (stu[i].score != stu[i - 1].score) {
			stu[i].final_rank = i + 1;
		}
		else {
			stu[i].final_rank = stu[i - 1].final_rank;
		}
	}

	printf("%d\n", num_testees);
	for (int i = 0; i < num_testees; ++i) {
		printf("%s %d %d %d\n", stu[i].reg_num, stu[i].final_rank, stu[i].local, stu[i].local_rank);
	}
}


//int main() {
//	pat_a1025();
//	return 0;
//}