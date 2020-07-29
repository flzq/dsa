#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp_pat_a1040[1010][1010]{ 0 };
class Pat_a1040 {
	// DP法
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

class Pat_a1040_hash {
	// 字符串hash方法
	int ans{ 0 };
	long long P{ 10000019 }, MOD{ 1000000007 }, powP[1100];
	vector<long long> H1, H2;
	string str;
public:
	Pat_a1040_hash() {
		powP[0] = 1;
		for (int i = 1; i < 1010; ++i) {
			powP[i] = (powP[i - 1] * P) % MOD;
		}
	}
	void pat_a1040() {
		getline(cin, str);
		calH(H1, str);
		reverse(str.begin(), str.end());
		calH(H2, str);
		// 对于奇数长度的子串
		for (int i = 0; i < str.length(); ++i) {
			// [L, R] 进行二分搜索寻找
			int max_len = min(i, (int)str.length() - i - 1) + 1; // 对于binary search 搜索子串的半径范围为[0, n]
			ans = max(ans, binary_search(0, max_len, i, str.length(), 0)*2+1);
		}
		// 对于偶数长度的子串
		for (int i = 0; i < str.length(); ++i) {
			int max_len = min(i + 1, (int)str.length() - i - 1) + 1;
		}
		printf("%d", ans);
	}
	void calH(vector<long long>& H, string& str) {
		H.push_back(str[0]);
		for (int i = 1; i < str.length(); ++i) {
			H.push_back((H[i - 1] * P + str[i]) % MOD);
		}
	}
	long long calsubH(vector<long long>& H, int L, int R) {
		// H[i...j] = H[j] - H[i-1]*P^(j-i+1)
		if (L == 0) {
			return H[R];
		}
		return (H[R] - H[L - 1] * powP[R - L + 1] % MOD + MOD) % MOD;
	}
	int binary_search(int L, int R, int i, int len, int is_even) {
		// 找到最后一个满足 HashL == HashR，也就是找到第一个满足 HashL != HashR
		while (L < R) {
			int mid = (L + R) / 2;
			int H1L = i - mid + is_even, H1R = i;
			int H2L = len - 1 - i - mid, H2R = len - 1 - i - is_even;
			if (calsubH(H1, H1L, H1R) == calsubH(H2, H2L, H2R)) {
				L = mid + 1;
			}
			else {
				R = mid;
			}
		}

		return L - 1;
	}
};

//int main() {
//	//Pat_a1040 pat_a1040;
//	Pat_a1040_hash pat_a1040;
//	pat_a1040.pat_a1040();
//	return 0;
//}