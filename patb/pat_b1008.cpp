#include <cstdio>

void pat_b1008() {
	/*
		pat_b1008_simple��δ��ԭ������в���
		���ǰ������⣬Ҫ�����ٵ��ƶ�����
		���ܵĽⷨ��
			�� N % M == 0 ʱ�����鲻��Ҫ�ƶ����ƶ�0��
			�� N % M != 0 ʱ���������ٵ��ƶ�����Ӧ��Ϊ����������²⣩
				�� N-M λ�ý����ƶ���һ���ƶ� N �Σ����ܵõ�˳��
	*/
	int N, M;
	scanf("%d%d", &N, &M);
	// ��������
	int* data = new int[N];
	for (int i = 0; i < N; ++i) {
		scanf("%d", &data[i]);
	}
	M = M % N;
	int cnt{ 0 }; // �����ƶ��˼���
	if (M != 0) { // M��Ϊ0����Ҫ�ƶ�������ֱ�����
		// ��N-Mλ�õ�Ԫ�ؿ�ʼ�ƶ�
		for (int i = N - M, tmp, tmp_idx; i < N; ++i) {
			tmp = data[i];
			tmp_idx = i;
			while ((tmp_idx - M + N) % N != i) {
				data[tmp_idx] = data[(tmp_idx - M + N) % N];
				tmp_idx = (tmp_idx - M + N) % N;
				++cnt;
			}
			data[tmp_idx] = tmp;
			++cnt;
			if (cnt == N) {
				break;
			}
		}
	}
	// ���
	for (int i = 0; i < N; ++i) {
		if (i != N - 1) {
			printf("%d ", data[i]);
		}
		else {
			printf("%d", data[i]);
		}
	}
}