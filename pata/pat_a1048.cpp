#include <cstdio>

void pat_a1048() {
	// ʹ��hash_table
	// ���Ե�3��ע��v2��Ҫv2>=0 && v2<=500, ��ֹv2Խ��
	int N, M;
	int hash_table[510]{ 0 }; // ��Ӧ��ֵӲ�ҵ�����
	scanf("%d%d", &N, &M);
	for (int i = 0, coin; i < N; ++i) {
		scanf("%d", &coin);
		++hash_table[coin];
	}
	bool flag = false; // �Ƿ��н�
	for (int v1 = 1, v2; v1 < 501; ++v1) {
		// v1<=v2
		if (hash_table[v1] != 0) {
			--hash_table[v1];
			v2 = M - v1;
			if (v2 >= 0 && v2 <= 500 && hash_table[v2] != 0 && v2 >= v1) { // v2>=0 && v2<=500����ֹv2Խ��
				flag = true;
				printf("%d %d", v1, v2);
				break;
			}
		}
	}
	if (flag == false) {
		printf("No Solution");
	}
}

void pat_a1048_2() {
	// ʹ�ö��ַ�
	int N, M;
	int coins[100000];
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &coins[i]);
	}
	// V1�ӵ�0ö��ʼö��
	int flag = true; // �н������
	for (int i = 0; i < N; ++i) {
		int V1 = coins[i];
		// ��[i+1, N+1]�ҵ���ֵ�պ�ΪM-V1��coin
		int left = i + 1, right = N + 1, mid;
		while (left < right) {
			mid = (left + right) / 2;

		}
	}
}

//int main() {
//	pat_a1048();
//	return 0;
//}