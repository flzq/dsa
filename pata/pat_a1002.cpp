#include <cstdio>
#include <vector>
using std::vector;

/*
	Ҫע��ϵ����Ӻ󣬸������Ϊ0
*/

void pat_a1002() {
	double poly[1010]{ 0 }; // ���ڴ洢��Ӧָ����ϵ��
	int K;
	int exp; // ָ��
	double coef; // ϵ��
	int cnt{ 0 }; // ϵ����0��ĸ���
	scanf("%d", &K);
	// �����һ������ʽ
	while (K--) {
		scanf("%d%lf", &exp, &coef);
		poly[exp] = coef;
	}
	// ����ڶ�������ʽ���������
	scanf("%d", &K);
	while (K--) {
		scanf("%d%lf", &exp, &coef);
		poly[exp] += coef;
	}
	// ����ϵ����0��ĸ���
	for (int i = 0; i <= 1000; ++i) {
		if (poly[i] != 0) {
			++cnt;
		}
	}
	printf("%d", cnt);
	for (int i = 1000; i >= 0; --i) {
		if (poly[i] != 0) {
			printf(" %d %.1f", i, poly[i]);
		}
	}
}


