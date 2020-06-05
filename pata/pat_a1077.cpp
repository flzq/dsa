#include <cstdio>

void pat_a1077() {
	int N;
	char lines[100][257];
	for (int i = 0; i < N; ++i) {
		fgets(lines[i], 257, stdin);
		printf("%d: ", i);
		puts(lines[i]);
	}
}


int main() {
	pat_a1077();
	return 0;
}