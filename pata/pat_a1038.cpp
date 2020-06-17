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
	// ���ĳ��segment��ȫ0, ���ܵ�һ�����
	int N;
	string ans;
	// char segments[10000][9];
	string segments[10000];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		cin >> segments[i];
	}
	// ����
	// ��Ϊ�������ֺϳ�һ�����ֺ󳤶�һ�������ÿ�δ�ÿ��segment��ѡ��ͷ��С�ģ�
	// ��ͬѡ��ڶ�λ��С�ģ�������ͬѡ�����λ��С�ġ�������ǰ��һ��ʱ��ѡ�񳤶ȸ�����
	sort(segments, segments + N, cmp_pat_a1038);
	// ����������������ƴ��
	for (int i = 0; i < N; ++i) {
		ans += segments[i];
	}
	// ȥ��ǰ��0
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