#include <cstdio>
char words[90][90];
void pat_b1009() {
	int cnt{ 0 };
	while (scanf("%s", words[cnt]) != EOF) {
		++cnt; // ע��cntһ��Ҫ�ں������м�һ,����ᵼ�¶�һ
	}
	for (int i = cnt - 1; i >= 0; --i) {
		printf("%s", words[i]);
		if (i != 0) {
			printf(" ");
		}
	}
}

//int main() {
//	pat_b1009();
//}