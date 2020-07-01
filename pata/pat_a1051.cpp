#include <cstdio>
#include <stack>
#include <vector>
using std::stack;
using std::vector;

void pat_a1051() {
	int M, N, K, data;
	scanf("%d%d%d", &M, &N, &K);
	for (int i = 0; i < K; ++i) {
		vector<int> iv;
		stack<int> st;

		// ��������
		for (int j = 0; j < N; ++j) {
			scanf("%d", &data);
			iv.push_back(data);
		}

		// �ж�, ģ��ջ����ջ����ջ
		bool flag = true; // ���ϳ�ջ˳��
		int index{ 0 };
		for (int j = 1; j <= N; ++j) {
			st.push(j);
			if (st.size() > M) {
				flag = false;
				break;
			}
			while (st.empty() == false && st.top() == iv[index]) {
				st.pop();
				++index;
			}
		}
		if (st.empty() && flag == true) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}

//int main() {
//	pat_a1051();
//	return 0;
//}