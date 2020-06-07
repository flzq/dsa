#include <cstdio>
#include <algorithm>
#include <cstring>
using std::sort;

struct Rich_pat_a1055 {
	char name[9];
	int age, worth;
}richest[100000];

// compare net worths
bool cmp_pat_a1055(Rich_pat_a1055& a, Rich_pat_a1055& b) {
	if (a.worth != b.worth) {
		return a.worth > b.worth;
	}
	else if (a.age != b.age) {
		return a.age < b.age;
	}
	else {
		return strcmp(a.name, b.name) < 0;
	}
}

void pat_a1055() {
	int N, K, query, start, end;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%s %d %d", richest[i].name, &richest[i].age, &richest[i].worth);
	}
	// °´worth, ÄêÁä, nameÅÅÐò
	sort(richest, richest + N, cmp_pat_a1055);
	for (int i = 0; i < K; ++i) {
		scanf("%d%d%d", &query, &start, &end);
		printf("Case #%d:\n", i + 1);
		int cnt{ 0 };
		for (int j = 0; j < N; ++j) {
			if (richest[j].age >= start && richest[j].age <= end && cnt < query) {
				printf("%s %d %d\n", richest[j].name, richest[j].age, richest[j].worth);
				++cnt;
			}
		}
		if (cnt == 0) {
			printf("None\n");
		}
	}
}

//int main() {
//	pat_a1055();
//	return 0;
//}