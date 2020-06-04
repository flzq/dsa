#include <cstdio>
#include <cstring>

void pat_a1005() {
	char digs[110];
	const char* eng[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int sum{ 0 };
	int len;
	scanf("%s", digs);
	len = strlen(digs);
	for (int i = 0; i < len; ++i) {
		sum += (digs[i] - '0');
	}
	sprintf(digs, "%d", sum);
	len = strlen(digs);
	for (int i = 0; i < len; ++i) {
		printf("%s", eng[digs[i]-'0']);
		if (i < len - 1) {
			printf(" ");
		}
	}

}

//int main() {
//	pat_a1005();
//	return 0;
//}