#include <cstdio>
#include <algorithm>
using std::sort;

void pat_b1005() {
	bool hash_table[110]{ false }; // 记录某个数是否被其他数覆盖
	int num[100]{ 0 }; // 记录输入的数字
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d", &num[i]);
		// 计算该数字到1中遇到的数字
		for (int j = num[i]; j != 1;) {
			if (j % 2 == 0) {
				j /= 2;
			}
			else{
				j = (3 * j + 1) / 2;
			}
			if (j > 1 && j <= 100) {
				hash_table[j] = true;
			}
		}
	}
	// 统计关键数个数
	int cnt{ 0 };
	for (int i = 0; i < K; ++i) {
		if (hash_table[num[i]] == false) {
			++cnt;
		}
	}
	// 从大到小输出关键数
	// 将输入数字排序
	sort(num, num + K);
	for (int i = K - 1; i >= 0; --i) {
		if (hash_table[num[i]] == false) {
			printf("%d", num[i]);
			--cnt;
			//if (i != 0) { // 注意：当中间某个数输出，后面都不输出时，输出空格会格式错误, 用"_"可以看到结果，所以要用cnt计算
			//	printf("_");
			//}
			if (cnt > 0) {
				printf(" ");
			}
		}
	}
}

//int main() {
//	pat_b1005();
//	return 0;
//}