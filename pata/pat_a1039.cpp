#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::sort;
using std::set;


/*
 * 字符串hash
 * 3个大写字母+1个数字：用26进制并且把最后一个数字拼接上
 */
 // 将map使用字符串hash代替，通过测试点5
set<int> hashTable_pat_a1039[26 * 26 * 26 * 10];
int hashFunc_pat_a1039(char str[], int len)
{
	int res = 0;
	for (int i = 0; i < len; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			res = res * 26 + (str[i] - 'A');
		}
		else {
			res = res * 10 + (str[i] - '0');
		}
	}

	return res;
}

void pat_a1039_1() {
	// 将map使用字符串hash代替，通过测试点5
	int N, K, course_id, num, name_id;
	char s[5];

	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d%d", &course_id, &num);
		for (int j = 0; j < num; ++j) {
			scanf("%s", s);
			name_id = hashFunc_pat_a1039(s, strlen(s));
			//printf("%d ", name_id);
			hashTable_pat_a1039[name_id].insert(course_id);
		}
		//printf("\n");
	}
	for (int i = 0; i < N; ++i) {
		scanf("%s", s);
		name_id = hashFunc_pat_a1039(s, strlen(s));
		printf("%s %d", s, hashTable_pat_a1039[name_id].size());
		for (set<int>::iterator it = hashTable_pat_a1039[name_id].begin();
			it != hashTable_pat_a1039[name_id].end(); ++it) {
			printf(" %d", *it);
		}
		printf("\n");
	}

}

void pat_a1039_2() {
	// 因为使用了map，测试点5运行超时
	int N, K, id, num_course_stu;
	string name;
	map<string, vector<int>> m;
	set<string> s;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d%d", &id, &num_course_stu);
		for (int j = 0; j < num_course_stu; ++j) {
			cin >> name;
			m[name].push_back(id);
			s.insert(name);
		}
	}
	for (set<string>::iterator it = s.begin(); it != s.end(); ++it) {
		sort(m[*it].begin(), m[*it].end());
	}
	for (int i = 0; i < N; ++i) {
		cin >> name;
		if (m.find(name) != m.end()) {
			 cout << name << " " << m[name].size();
			for (int i = 0; i < m[name].size(); ++i) {
				cout << " " << m[name][i];
			}
			cout << endl;
		}
		else {
			cout << name << " " << 0 << endl;
		}
	}
}


//int main() {
//	pat_a1039_1();
//
//	return 0;
//}