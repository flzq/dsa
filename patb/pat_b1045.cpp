#include <cstdio>

void pat_b1045() {
    // 如果没有主元，第一行输出0，第二行要输出一个换行，否则测试点2不通过
    int N, max{ -1 };
    int numbers[100010];
    int max_num[100010]; // 存储当前位置之前（包括当前位置）最大的值
    int min_num[100010]; // 存储当前位置之后（包括当前位置）最小的值
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &numbers[i]);
        // 找到当前位置之前（包括当前位置）最大的值
        if (max < numbers[i]) {
            max_num[i] = numbers[i];
            max = numbers[i];
        }
        else {
            max_num[i] = max;
        }
    }
    // 当前位置之后（包括当前位置）最小的值
    int min{ 1000000000 };
    for (int i = N - 1; i >= 0; --i) {
        if (min > numbers[i]) {
            min_num[i] = numbers[i];
            min = numbers[i];
        }
        else {
            min_num[i] = min;
        }
    }
    // 判断是否为主元
    int cnt_pivot{ 0 }; // 计算主元数量
    int pivots[100010];
    for (int i = 0; i < N; ++i) {
        if (numbers[i] >= max_num[i] && numbers[i] <= min_num[i]) {
            pivots[cnt_pivot++] = numbers[i];
        }
    }
    printf("%d\n", cnt_pivot);
    for (int i = 0; i < cnt_pivot; ++i) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", pivots[i]);
    }
    if (cnt_pivot == 0) {
        printf("\n");
    }
}

//int main() {
//    pat_b1045();
//    return 0;
//}