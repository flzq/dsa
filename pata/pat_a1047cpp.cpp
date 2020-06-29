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

char name_pat_a1047_1[maxn_pat_a1047_1][5]; // 存储每个学生的姓名
vector<int> course_pat_a1047_1[maxk_pat_a1047_1]; // 存储每门课选的学生的编号，课程从1开始编号
bool cmp_pat_a1047_1(int a, int b)
{
	return strcmp(name_pat_a1047_1[a], name_pat_a1047_1[b]) < 0;
}

void pat_a1047_1() {
	int N, K, num, course_id;
	char s[5];

	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		// 存储学生姓名
		scanf("%s%d", name_pat_a1047_1[i], &num);
		for (int j = 0; j < num; ++j) {
			// 读入该学生选的课程编号
			scanf("%d", &course_id);
			// 存储每门课学生编号
			course_pat_a1047_1[course_id].push_back(i);
		}
	}
	// 按照字母序输出学生姓名
	for (int i = 1; i <= K; ++i) {
		// 输出第 i 门课的信息
		// 课程编号从1开始
		// 每门课学生的数量
		// 按照字母序对course[i]中的学生编号排序
		sort(course_pat_a1047_1[i].begin(), course_pat_a1047_1[i].end(), cmp_pat_a1047_1);
		int stu_num = course_pat_a1047_1[i].size();
		printf("%d %d\n", i, stu_num);
		for (int j = 0; j < stu_num; ++j) {
			// 打印出每门课选出的学生的名字
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