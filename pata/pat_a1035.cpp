#include <cstdio>
#include <cstring>

bool check(char* pass) {
	int len = strlen(pass);
	int is_mod = false;
	for (int i = 0; i < len; ++i) {
		if (pass[i] == '1') {
			pass[i] = '@';
			is_mod = true;
		}
		else if (pass[i] == '0') {
			pass[i] = '%';
			is_mod = true;
		}
		else if (pass[i] == 'l') {
			pass[i] = 'L';
			is_mod = true;
		}
		else if (pass[i] == 'O') {
			pass[i] = 'o';
			is_mod = true;
		}
	}
	return is_mod;
}

void pat_a1035() {
	char user[11];
	char pass[11];
	char users[1000][11];
	char passes[1000][11];
	int N, cnt{ 0 };
	bool is_mod;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s%s", user, pass);
		is_mod = check(pass);
		if (is_mod) {
			strcpy(users[cnt], user);
			strcpy(passes[cnt], pass);
			++cnt;
		}
	}
	if (cnt != 0) {
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; ++i) {
			printf("%s %s\n", users[i], passes[i]);
		}
	}
	else {
		if (N == 1) {
			printf("There is 1 account and no account is modified");
		}
		else {
			printf("There are %d accounts and no account is modified", N);
		}
	}
}

//int main() {
//	pat_a1035();
//	return 0;
//}