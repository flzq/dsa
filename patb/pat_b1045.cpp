#include <cstdio>

void pat_b1045() {
    // ���û����Ԫ����һ�����0���ڶ���Ҫ���һ�����У�������Ե�2��ͨ��
    int N, max{ -1 };
    int numbers[100010];
    int max_num[100010]; // �洢��ǰλ��֮ǰ��������ǰλ�ã�����ֵ
    int min_num[100010]; // �洢��ǰλ��֮�󣨰�����ǰλ�ã���С��ֵ
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &numbers[i]);
        // �ҵ���ǰλ��֮ǰ��������ǰλ�ã�����ֵ
        if (max < numbers[i]) {
            max_num[i] = numbers[i];
            max = numbers[i];
        }
        else {
            max_num[i] = max;
        }
    }
    // ��ǰλ��֮�󣨰�����ǰλ�ã���С��ֵ
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
    // �ж��Ƿ�Ϊ��Ԫ
    int cnt_pivot{ 0 }; // ������Ԫ����
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