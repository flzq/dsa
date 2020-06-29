#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using std::vector;
using std::string;
using std::sort;


const int maxn_pat_a1047_1 = 40010;
const int maxk_pat_a1047_1 = 2510;

char name_pat_a1047_1[maxn_pat_a1047_1][5]; // �洢ÿ��ѧ��������
vector<int> course_pat_a1047_1[maxk_pat_a1047_1]; // �洢ÿ�ſ�ѡ��ѧ���ı�ţ��γ̴�1��ʼ���
bool cmp_pat_a1047_1(int a, int b)
{
	return strcmp(name_pat_a1047_1[a], name_pat_a1047_1[b]) < 0;
}

void pat_a1047_1() {
	int N, K, num, course_id;
	char s[5];

	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		// �洢ѧ������
		scanf("%s%d", name_pat_a1047_1[i], &num);
		for (int j = 0; j < num; ++j) {
			// �����ѧ��ѡ�Ŀγ̱��
			scanf("%d", &course_id);
			// �洢ÿ�ſ�ѧ�����
			course_pat_a1047_1[course_id].push_back(i);
		}
	}
	// ������ĸ�����ѧ������
	for (int i = 1; i <= K; ++i) {
		// ����� i �ſε���Ϣ
		// �γ̱�Ŵ�1��ʼ
		// ÿ�ſ�ѧ��������
		// ������ĸ���course[i]�е�ѧ���������
		sort(course_pat_a1047_1[i].begin(), course_pat_a1047_1[i].end(), cmp_pat_a1047_1);
		int stu_num = course_pat_a1047_1[i].size();
		printf("%d %d\n", i, stu_num);
		for (int j = 0; j < stu_num; ++j) {
			// ��ӡ��ÿ�ſ�ѡ����ѧ��������
			printf("%s\n", name_pat_a1047_1[course_pat_a1047_1[i][j]]);
		}
		/*if(i!=K) {
			printf("\n");
		}*/
	}
}


void pat_a1047_2() {
	int N, K, total_course, id;
	char str[5];
	vector<string> course[2510];
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%s%d", str, &total_course);
		for (int j = 0; j < total_course; ++j) {
			scanf("%d", &id);
			course[id].push_back(str);
		}
	}
	for (int i = 1; i <= K; ++i) {
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end());
		for (int j = 0; j < course[i].size(); ++j) {
			printf("%s\n", course[i][j].c_str());
		}
	}
}


//int main() {
//	pat_a1047_2();
//
//	return 0;
//}