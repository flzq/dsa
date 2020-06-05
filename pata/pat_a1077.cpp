#include <cstdio>
#include <cstring>

void pat_a1077() {
	int N;
	char lines[100][257];
	bool flag{ true }; // �й�ͬ��׺
	scanf("%d\n", &N);
	for (int i = 0; i < N; ++i) {
		fgets(lines[i], 257, stdin);
	}

	// �ȴ�ǰ�������ҵ���ͬ�ĺ�׺
	int len_a = strlen(lines[0]);
	int len_b = strlen(lines[1]);
	char suffix[257];
	int cnt{ 0 }; // �����׺���ַ���
	for (len_a -= 2, len_b-=2; len_a >= 0 && len_b >= 0; --len_a, --len_b) {
		// --len_a, --len_b: ��Ϊÿ���ַ��������һ�����з�,����Ҫ�ӻ��з�ǰһ���ַ���ʼ�Ƚ�
		if (lines[0][len_a] == lines[1][len_b] && lines[0][len_a] != ' ' && lines[1][len_b] != ' ') {
			suffix[cnt++] = lines[1][len_b];
		}
		else {
			break;
		}
	}
	suffix[cnt] = '\0';
	if (cnt == 0) { // ��ʾǰ�����ַ���û����ͬ��׺
		flag = false;
	}
	// �ӵ������ַ���ʼ�Ƚ��Ƿ��й�ͬ�ĺ�׺
	for (int i = 2; i < N; ++i) {
		len_a = strlen(lines[i]);
		len_a -= 2;
		int j;
		for (j = 0; j < cnt && len_a>=0; ++j, --len_a) {
			if (suffix[j] != lines[i][len_a]) {
				flag = false;
				break;
			}
		}
		if (flag == false || j < cnt) { // ��ʾlines[i] ��û�иú�׺
			flag = false;
			break;
		}

	}

	if (flag == false) {
		printf("nai");
	}
	else {
		for (int i = cnt - 1; i >= 0; --i) {
			printf("%c", suffix[i]);
		}
	}


}


//int main() {
//	pat_a1077();
//	return 0;
//}