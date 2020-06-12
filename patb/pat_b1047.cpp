#include <cstdio>

void pat_b1047() {
	int N, team_id, id, score; // ��������������(1-1000)����Ա���(1-10)���ɼ�
	int hash_table[1010]; // ��¼ÿ���ӵ��ܳɼ�
	for (int i = 0; i < 1010; ++i) {
		hash_table[i] = 0;
	}
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d-%d %d", &team_id, &id, &score);
		hash_table[team_id] += score;
	}
	int max{ -1 }, index_max;
	for (int i = 1; i <= 1000; ++i) {
		if (hash_table[i] > max) {
			max = hash_table[i];
			index_max = i;
		}
	}
	printf("%d %d", index_max, max);
}

//int main() {
//	pat_b1047();
//	return 0;
//}