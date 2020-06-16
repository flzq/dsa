#include <cstdio>
#include <algorithm>
#include <cstring>
using std::sort;

struct Digit_pat_a1038 {
	char digit[9];
};

bool cmp_pat_a1038(Digit_pat_a1038& a, Digit_pat_a1038& b) {
	int len_a = strlen(a.digit);
	int len_b = strlen(b.digit);
	int i;
	for (i = 0; i < len_a && i < len_b; ++i) {
		if (a.digit[i] < b.digit[i]) {
			return true;
		}
	}
	// 前面数字都相同,长的数字排在前面
	if (i == len_a) {
		return false;
	}
	else {
		return true;
	}
}

void pat_a1038() {
	// 如果某个segment是全0, 则不能第一个输出
	int N;
	// char segments[10000][9];
	Digit_pat_a1038 segments[10000];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", segments[i].digit);
	}
	// 排序
	// 因为所有数字合成一个数字后长度一样，因此每次从每个segment中选择开头最小的，
	// 相同选择第二位最小的，继续相同选择第三位最小的。。。当前面一样时，选择长度更长的
	sort(segments, segments + N, cmp_pat_a1038);
	/*for (int i = 0; i < N; ++i) {
		printf("%s", segments[i].c_str());
	}*/
}


int main() {
	pat_a1038();

	return 0;
}