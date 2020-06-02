#include <cstdio>

void pat_b1009() {
	char words[80][81];
	int cnt{ 0 };
	while (scanf("%s", words[cnt++]) != EOF) {
		printf("word: %s\n", words[cnt]);
	}
}

int main() {
	pat_b1009();
}