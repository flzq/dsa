#include<cstdio>
#include <algorithm>
using std::sort;

struct User_pat_a1075 {
	int id{ 0 };
	int rank;
	int total_score{ 0 };
	int perfected_solved{ 0 };
	int p[6]; // -2��ʾ����û�ύ
	bool flag{ false }; // ��ʾ������Ŀ��û�б���ɹ�����������Ŀ��û���ύ
	User_pat_a1075() {
		for (int i = 1; i <= 6; ++i) {
			p[i] = -2;
		}
	}
}user[10010];

bool cmp_pat_a1075(User_pat_a1075& a, User_pat_a1075& b) {
	if (a.total_score != b.total_score) {
		return a.total_score > b.total_score;
	}
	else if (a.perfected_solved != b.perfected_solved) {
		return a.perfected_solved > b.perfected_solved;
	}
	else {
		return a.id < b.id;
	}
}

void pat_a1075() {
	int N, K, M, user_id, pro_id, score;
	int full_p[5]{ 0 }; // ��Ŀ������
	// ��������
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 1; i <= K; ++i) {
		scanf("%d", &full_p[i]);
	}
	// ��ʼ��user_id
	for (int i = 1; i <= N; ++i) {
		user[i].id = i;
	}
	// ����M���ύ
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &user_id, &pro_id, &score);
		if (user[user_id].p[pro_id] < score) {
			if (user[user_id].p[pro_id] == -2) { // �����һ��ͨ��
				if (score == -1) { // ����ʧ��, ����Ϊ0
					user[user_id].p[pro_id] = 0;
					user[user_id].total_score += 0;
					// user[user_id].flag = true; // ����ʧ��,����Ϊtrue
				}
				else {
					user[user_id].p[pro_id] = score;
					user[user_id].total_score += score;
					user[user_id].flag = true;
					if (score == full_p[pro_id]) {
						++user[user_id].perfected_solved;
					}
				}
			}
			else { // �����Ѿ��ύ����
				if (score == -1) { // ����ʧ��
					user[user_id].total_score -= user[user_id].p[pro_id];
					user[user_id].p[pro_id] = 0;
					user[user_id].total_score += user[user_id].p[pro_id];
					// user[user_id].flag = true; // ����ʧ��,����Ϊtrue
				}
				else {
					user[user_id].total_score -= user[user_id].p[pro_id];
					user[user_id].p[pro_id] = score;
					user[user_id].total_score += user[user_id].p[pro_id];
					if (score == full_p[pro_id]) {
						++user[user_id].perfected_solved;
					}
				}
			}
		}
	}
	// ����
	sort(user+1, user + N + 1, cmp_pat_a1075);
	int index{ 1 }; // �ҵ�����һ���ύ���ұ���ͨ����ͬѧid
	while (user[index].flag == false) {
		++index;
	}
	user[index].rank = 1;
	for (int i = index + 1, r = 1; i <= N; ++i) {
		if (user[i].flag == true) {
			if (user[index].total_score == user[i].total_score) {
				user[i].rank = user[index].rank;
			}
			else {
				user[i].rank = r + 1;
				index = i;
			}

			++r;
		}
	}
	// ���
	for (int i = 1; i <= N; ++i) {
		if (user[i].flag == true) {
			printf("%d %05d %d", user[i].rank, user[i].id, user[i].total_score);
			for (int j = 1; j <= K; ++j) {
				if (user[i].p[j] == -2) {
					printf(" -");
				}
				else {
					printf(" %d", user[i].p[j]);
				}
			}
			printf("\n");
		}

	}

}

//int main() {
//	pat_a1075();
//	return 0;
//}