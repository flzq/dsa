#include <cstdio>
#include <cstring>

// ע�������������1000λ����,����������洢

void pat_b1021() {
	char N[1010];
	int cnt[10]{ 0 };
	scanf("%s", N);
	int len = strlen(N);
	for (int i = 0; i < len; ++i) {
		++cnt[N[i] - '0'];
	}
	for (int i = 0; i < 10; ++i) {
		if (cnt[i] != 0) {
			printf("%d:%d\n", i, cnt[i]);
		}

	}
}


int main() {
	pat_b1021();

	return 0;
}