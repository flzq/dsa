#include <cstdio>
#include <cstring>

struct Age {
	char name[7];
	int year, month, day;
};

bool check(int year, int month, int day) {
	// �ж��Ƿ� <= 200
	// �Ϸ����ڣ�1814.9.6--2014.9.6
	if (year == 1814) { // �ж�1814������Ƿ�Ϸ�
		if (month < 9) {
			return false;
		}
		else if (month == 9 && day < 6) {
			return false;
		}
	}
	else if (year == 2014) { // �ж�2014������Ƿ�Ϸ�
		if (month > 9) {
			return false;
		}
		else if (month == 9 && day > 6) {
			return false;
		}
	}
	else if (year < 1814 || year > 2014) {
		return false;
	}
	return true;

}

void pat_b1028() {
	// max��¼��������������ˣ���������С���ˣ�����������������
	// min��¼��������������ˣ������������ˣ�������������С����
	char name[7];
	Age tmp, max, min; // tmp��ʱ��¼�������ݣ�max��¼��������������ˣ�min��¼���������������
	int N, cnt{ 0 }; // cnt��¼��Ч���ڸ���
	max.year = 1814, max.month = 9, max.day = 5;
	min.year = 2014, min.month = 9, min.day = 7;

	scanf("%d", &N);
	while (N--) {
		scanf("%s %d/%d/%d", tmp.name, &tmp.year, &tmp.month, &tmp.day);
		bool is_legal = check(tmp.year, tmp.month, tmp.day);
		if (is_legal == true) {
			++cnt;
			// max��¼���������������
			if (tmp.year == max.year) {
				if (tmp.month == max.month && tmp.day > max.day) {
					max = tmp;
				}
				else if (tmp.month > max.month) {
					max = tmp;
				}
			}
			else if (tmp.year > max.year) {
				max = tmp;
			}

			// min��¼���������������
			if (tmp.year == min.year) {
				if (tmp.month == min.month && tmp.day < min.day) {
					min = tmp;
				}
				else if (tmp.month < min.month) {
					min = tmp;
				}
			}
			else if (tmp.year < min.year) {
				min = tmp;
			}
		}
		// printf("%s %d %d %d %d\n", name, year, month, day, is_legal);
	}

	if (cnt != 0) {
		printf("%d %s %s", cnt, min.name, max.name); // max��¼��������������ˣ�min��¼���������������
	}
	else {
		printf("0"); // ��û�кϷ����ʱ��ֻ���0���������ָ�ʽ����
	}
}

