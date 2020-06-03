#include <cstdio>
#include <cstring>

bool check(char* id) {
	int weights[17] = { 7, 9,10,5, 8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char M[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	int weight{ 0 };
	// ºÏ≤È«∞17Œª
	for (int i = 0; i < 17; ++i) {
		if (id[i] - '0' > 9 || id[i] - '0' < 0) {
			return false;
		}
		weight += weights[i] * (id[i] - '0');
	}
	int Z = weight % 11;
	if (id[17] == M[Z]) {
		return true;
	}
	else {
		return false;
	}
}


void pat_b1031() {
	int N;
	char id[19];
	bool is_pass = true;
	scanf("%d", &N);
	while (N--) {
		scanf("%s", id);
		bool is_right = check(id);
		if (is_right == false) {
			is_pass = false;
			printf("%s\n", id);
		}
	}
	if (is_pass == true) {
		printf("All passed");
	}
}


//int main() {
//	pat_b1031();
//
//	return 0;
//}