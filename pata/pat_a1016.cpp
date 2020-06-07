#include <cstdio>
#include <algorithm>
#include <cstring>
using std::sort;

struct Cust_pat_a1016 {
	char name[21];
	char state[10]; // 记录上线还是下线
	int month, day, hour, minute;
}cus[1000];

bool cmp_phone_rate(Cust_pat_a1016& a, Cust_pat_a1016& b) {
	// 先按照字母序对顾客排序, 同一个顾客按照时间排序
	if (strcmp(a.name, b.name) != 0) {
		return strcmp(a.name, b.name) < 0;
	}
	else {
		if (a.day != b.day) {
			return a.day < b.day;
		}
		else if (a.hour != b.hour) {
			return a.hour < b.hour;
		}
		else {
			return a.minute < b.minute;
		}
	}
}

void pat_a1016() {
	// 输出时间上连续的同一个人on-line和off-line记录,如果on-line和off-line中间有一个off-line,则不符合规则
	int N;
	double rate[24], sum_rate{ 0 };
	for (int i = 0; i < 24; ++i) {
		scanf("%lf", &rate[i]);
		sum_rate += rate[i];
	}
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s %d:%d:%d:%d %s", cus[i].name, &cus[i].month, &cus[i].day, &cus[i].hour, &cus[i].minute, cus[i].state);
	}
	// 排序
	// 先按照字母序对顾客排序, 同一个顾客按照时间排序
	sort(cus, cus + N, cmp_phone_rate);
	//for (int i = 0; i < N; ++i) {
	//	printf("cout: %s %02d:%02d:%02d:%02d %s\n", cus[i].name, cus[i].month, cus[i].day, cus[i].hour, cus[i].minute, cus[i].state);
	//}
	for (int i = 0; i < N; ) {
		double total_fare{ 0 };
		bool flag = true;
		for (int j = i; j < N - 1; ++j) { // 对同一个顾客的记录进行处理
			if (strcmp(cus[i].name, cus[j+1].name) != 0) {
				i = j + 1;
				break;
			}
			if (strcmp(cus[j].state, "on-line") == 0 && strcmp(cus[j + 1].state, "off-line") == 0) {
				// 计算cus[j].day -> cus[j+1].day的总的费用和时间
				// 如果cus[j].day -> cus[j+1].day后，cus[j]的时间<=cus[j+1], 那么还要加上这一部分费用;
				// 如果cus[j].day -> cus[j+1].day后，cus[j]的时间>cus[j+1], 那么还要减去超过的这一部分费用;
				if (flag == true) {
					printf("%s %02d\n", cus[i].name, cus[i].month);
					flag = false;
				}
				double fare{ 0 };
				int minutes{ 0 };
				// 采用累加法计算时间
				Cust_pat_a1016 tmp = cus[j];
				while (tmp.day < cus[j + 1].day || tmp.hour < cus[j + 1].hour || tmp.minute < cus[j + 1].minute) {
					++tmp.minute;
					++minutes;
					fare += rate[tmp.hour];
					if (tmp.minute == 60) {
						tmp.minute = 0;
						++tmp.hour;
					}
					if (tmp.hour == 24) {
						tmp.hour = 0;
						++tmp.day;
					}
				}
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", cus[j].day, cus[j].hour, cus[j].minute, cus[j + 1].day, cus[j + 1].hour, cus[j + 1].minute, minutes, fare / 100);
				total_fare += fare;
			}
		}
		if (flag == false) {
			printf("Total amount: $%.2f\n", total_fare / 100);
		}
	}

}

//int main() {
//	pat_a1016();
//
//	return 0;
//}