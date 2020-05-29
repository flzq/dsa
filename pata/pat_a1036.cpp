#include <cstdio>

struct Score {
	char name[11];
	char id[11];
	char gender;
	int score;
	Score() {}
	Score(char gender_, int score_) : gender{ gender_ }, score{ score_ } {}
};

void pat_a1036() {
	Score lowest{'M', 101}; // 男生中最低的分数
	Score highest{'F', -1}; // 女生中最高的分数
	Score tmp;
	int N;
	scanf("%d", &N);
	while (N--) {
		scanf("%s %c %s %d", tmp.name, &tmp.gender, tmp.id, &tmp.score);
		if (tmp.gender == 'M') { // 找男生最低
			if (tmp.score < lowest.score) {
				lowest = tmp;
			}
		}
		else { // 找女生最高
			if (tmp.score > highest.score) {
				highest = tmp;
			}
		}
	}
	if (highest.score != -1) {
		printf("%s %s\n", highest.name, highest.id);
	}
	else {
		printf("Absent\n");
	}
	if (lowest.score != 101) {
		printf("%s %s\n", lowest.name, lowest.id);
	}
	else {
		printf("Absent\n");
	}
	if (highest.score != -1 && lowest.score != 101) {
		printf("%d", highest.score - lowest.score);
	}
	else {
		printf("NA\n");
	}
}


int main() {
	pat_a1036();
	return 0;
}