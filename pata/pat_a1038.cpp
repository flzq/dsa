#include <iostream>
#include <algorithm>
#include <string>
using std::sort;
using std::string;
using std::cin;
using std::cout;

bool cmp_pat_a1038(string& a, string& b) {
	if (a + b < b + a) {
		return true;
	}
	else {
		return false;
	}
}

void pat_a1038() {
	// 如果某个segment是全0, 则不能第一个输出
	int N;
	string ans;
	// char segments[10000][9];
	string segments[10000];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		cin >> segments[i];
	}
	// 排序
	// 因为所有数字合成一个数字后长度一样，因此每次从每个segment中选择开头最小的，
	// 相同选择第二位最小的，继续相同选择第三位最小的。。。当前面一样时，选择长度更长的
	sort(segments, segments + N, cmp_pat_a1038);
	// 将排序后的所有数字拼接
	for (int i = 0; i < N; ++i) {
		ans += segments[i];
	}
	// 去除前导0
	while (ans.size() != 0 && ans[0] == '0') {
		ans.erase(ans.begin());
	}
	if (ans.size() > 0) {
		cout << ans;
	}
	else {
		cout << 0;
	}
}


//int main() {
//	pat_a1038();
//
//	return 0;
//}