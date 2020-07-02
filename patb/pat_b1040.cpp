#include <cstdio>
#include <cstring>

void pat_b1040() {
    char str[100010];
    int PA[100010]; // 统计A之前P的个数
    int AT[100010]; // 统计A之后T的个数
    scanf("%s", str);
    int len_str = strlen(str);
    // 统计A之前P的个数
    for (int i = 0; i < len_str; ++i) {
        // 判断当前元素是否为P
        int cnt_p = 0;
        if (str[i] == 'P') {
            cnt_p = 1;
        }
        if (i == 0) {
            PA[i] = cnt_p;
        }
        else {
            PA[i] = PA[i - 1] + cnt_p;
        }
    }
    // 统计A之后T的个数
    for (int i = len_str - 1; i >= 0; --i) {
        // 判断当前元素是否为T
        int cnt_t = 0;
        if (str[i] == 'T') {
            cnt_t = 1;
        }
        if (i == len_str - 1) {
            AT[i] = cnt_t;
        }
        else {
            AT[i] = AT[i + 1] + cnt_t;
        }
    }
    // 循环计算一共有多少个PAT
    int cnt_pat = 0;
    for (int i = 0; i < len_str; ++i) {
        if (str[i] == 'A') {
            cnt_pat = (cnt_pat + (PA[i] * AT[i])) % (1000000007);
        }
    }
    printf("%d", cnt_pat);
}


//int main() {
//    pat_b1040();
//    return 0;
//}