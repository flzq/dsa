#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;



struct Stu {
	char id[9];
	int de, cai, sum;
	int cat; // Àà±ğ
}stu[100000];

bool cmp(Stu& a, Stu& b) {
	if (a.cat != b.cat) {
		return a.cat < b.cat;
	}
	else if (a.sum != b.sum) {
		return a.sum > b.sum;
	}
	else if (a.de != b.de) {
		return a.de > b.de;
	}
	else {
		return strcmp(a.id, b.id) < 0;
	}
}

void pat_b1015() {
	int N, L, H, cnt{ 0 };
	char id[9];
	int de, cai;
	scanf("%d%d%d", &N, &L, &H);
	for (int i = 0; i < N; ++i) {
		scanf("%s%d%d", id, &de, &cai);
		if (de >= L && cai >= L) {
			strcpy(stu[cnt].id, id);
			stu[cnt].de = de;
			stu[cnt].cai = cai;
			stu[cnt].sum = stu[cnt].de + stu[cnt].cai;

			if (stu[cnt].de >= H && stu[cnt].cai >= H) {
				stu[cnt].cat = 1;
			}
			else if (stu[cnt].de >= H && stu[cnt].cai < H) {
				stu[cnt].cat = 2;
			}
			else if (stu[cnt].de < H && stu[cnt].cai < H && stu[cnt].de >= stu[cnt].cai) {
				stu[cnt].cat = 3;
			}
			else {
				stu[cnt].cat = 4;
			}

			++cnt;
		}
	}
	// ÅÅĞò
	sort(stu, stu + cnt, cmp);

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i) {
		printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
	}


}

//int main() {
//	pat_b1015();
//	return 0;
//}