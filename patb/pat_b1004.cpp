#include <cstdio>
#include <cstring>

struct Node {
	char name[12];
	char id[12];
	int score;
};

void pat_b1004() {
	int n;
	int max_score{ -1 }, min_score{101}, score;
	char name[12]; // 姓名
	char id[12]; // 学号
	Node stu[2]; // stu[0]：最高成绩；stu[1]：最低成绩

	scanf("%d", &n);
	while (n--) {
		scanf("%s%s%d", name, id, &score);
		if (score > max_score) {
			max_score = score;
			stu[0].score = score;
			strcpy(stu[0].name, name);
			strcpy(stu[0].id, id);
		}

		if (score < min_score) {
			min_score = score;
			stu[1].score = score;
			strcpy(stu[1].name, name);
			strcpy(stu[1].id, id);
		}
	}
	printf("%s %s\n", stu[0].name, stu[0].id);
	printf("%s %s", stu[1].name, stu[1].id);
}


