#include <cstdio>
#include <cstring>
int dp_pat_a1040[1010][1010]{ 0 };
class Pat_a1040 {
	char str[1010], len_str;
	int max_len{ 1 };
public:
	void pat_a1040() {
		fgets(str, 1000, stdin);
		len_str = strlen(str);
		for (int i = 0; i < len_str; ++i) {
			dp_pat_a1040[i][i] = 1;
			if (i < len_str - 1 && str[i] == str[i+1]) {
				dp_pat_a1040[i][i + 1] = 1;
				max_len = 2;
			}
		}
		for (int k = 3; k <= len_str; ++k) {
			for (int i = 0; i <= len_str - k; ++i) {
				int j = i + k - 1;
				if (str[i] == str[j] && dp_pat_a1040[i+1][j-1] == 1) {
					dp_pat_a1040[i][j] = 1;
					max_len = k;
				}
				else {
					dp_pat_a1040[i][j] = 0;
				}
			}
		}
		printf("%d", max_len);
	}
};

//int main() {
//	Pat_a1040 pat_a1040;
//	pat_a1040.pat_a1040();
//	return 0;
//}