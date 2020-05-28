#include <cstdio>
#include <cstring>

struct Age {
	char name[7];
	int year, month, day;
};

bool check(int year, int month, int day) {
	// 判断是否 <= 200
	// 合法日期：1814.9.6--2014.9.6
	if (year == 1814) { // 判断1814年的人是否合法
		if (month < 9) {
			return false;
		}
		else if (month == 9 && day < 6) {
			return false;
		}
	}
	else if (year == 2014) { // 判断2014年的人是否合法
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
	// max记录出身日期最晚的人，即年龄最小的人，而不是年龄最大的人
	// min记录出身日期最早的人，即年龄最大的人，而不是年龄最小的人
	char name[7];
	Age tmp, max, min; // tmp临时记录输入数据，max记录出身日期最晚的人，min记录出身日期最早的人
	int N, cnt{ 0 }; // cnt记录有效日期个数
	max.year = 1814, max.month = 9, max.day = 5;
	min.year = 2014, min.month = 9, min.day = 7;

	scanf("%d", &N);
	while (N--) {
		scanf("%s %d/%d/%d", tmp.name, &tmp.year, &tmp.month, &tmp.day);
		bool is_legal = check(tmp.year, tmp.month, tmp.day);
		if (is_legal == true) {
			++cnt;
			// max记录出身日期最晚的人
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

			// min记录出身日期最早的人
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
		printf("%d %s %s", cnt, min.name, max.name); // max记录出身日期最晚的人，min记录出身日期最早的人
	}
	else {
		printf("0"); // 当没有合法输出时，只输出0，否则会出现格式错误
	}
}

