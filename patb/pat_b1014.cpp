#include <cstdio>
#include <cstring>

void pat_b1014() {
	char str[4][61];
	const char* days[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

	// ��������
	scanf("%s%s%s%s", str[0], str[1], str[2], str[3]);

	// ��ǰ��2���ַ�����, �ҵ���һ����ͬ�Ĵ�дӢ����ĸ [A-G]
	int s1_index{ 0 };
	int s1_len = strlen(str[0]);
	while (true) {

		if ((str[0][s1_index] == str[1][s1_index]) && str[0][s1_index] >= 'A' && str[0][s1_index] <= 'G') {
			printf("%s ", days[str[0][s1_index] - 'A']);
			break;
		}
		++s1_index;

	}
	int day = str[0][s1_index] - 'A';
	// ��s1_index+1��ʼ,��ǰ2���ַ������ҵ�ʱ��[0-9, A-N]
	++s1_index;
	while (true) {
		if (str[0][s1_index] == str[1][s1_index] && str[0][s1_index] >= '0' && str[0][s1_index] <= '9') {
			printf("%02d", str[0][s1_index] - '0');
			break;
					}
		else if (str[0][s1_index] == str[1][s1_index] && str[0][s1_index] >= 'A' && str[0][s1_index] <= 'N') {
			printf("%02d", str[0][s1_index] - 'A' + 10);
			break;
		}
		++s1_index;
	}

	// �Ӻ������ַ������ҵ���ͬλ������ͬ���ַ�
	int len = strlen(str[2]) < strlen(str[3]) ? strlen(str[2]) : strlen(str[3]);
	int s3_index{ 0 };
	while (true) {
		if (str[2][s3_index] == str[3][s3_index] &&
			((str[2][s3_index] >= 'a' && str[2][s3_index] <= 'z') || (str[2][s3_index] >= 'A' && str[2][s3_index] <= 'Z'))) {
			printf(":%02d", s3_index);
			break;
		}
		++s3_index;
	}

}

//int main() {
//	pat_b1014();
//
//	return 0;
//}