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
	printf("( %d %d )", len_a, len_b);
	int i;
	for (i = 0; i < len_a && i < len_b; ++i) {
		if (a.digit[i] < b.digit[i]) {
			return true;
		}
	}
	// ǰ�����ֶ���ͬ,������������ǰ��
	if (i == len_a) {
		return false;
	}
	else {
		return true;
	}
}
Digit_pat_a1038 segments[10000];
void pat_a1038() {
	// ���ĳ��segment��ȫ0, ���ܵ�һ�����
	int N;
	// char segments[10000][9];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", segments[i].digit);
	}
	cmp_pat_a1038(segments[0], segments[1]);
	// ����
	// ��Ϊ�������ֺϳ�һ�����ֺ󳤶�һ�������ÿ�δ�ÿ��segment��ѡ��ͷ��С�ģ�
	// ��ͬѡ��ڶ�λ��С�ģ�������ͬѡ�����λ��С�ġ�������ǰ��һ��ʱ��ѡ�񳤶ȸ�����
	/*sort(segments, segments + N, cmp_pat_a1038);
	for (int i = 0; i < N; ++i) {
		printf("%s", segments[i].digit);
	}*/
}


int main() {
	pat_a1038();

	return 0;
}