#include <algorithm>
#include <cstdio>
using std::sort;


struct Station_pat_a1033 {
	double avg_price, distance, bet_dis{ 0 };
};

bool cmp_pat_a1033(Station_pat_a1033&a, Station_pat_a1033& b) {
	return a.distance < b.distance;
}


void pat_a1033() {
	double capacity, distance, avg_dis;
	int N;
	Station_pat_a1033 stations[500];
	// 读入数据
	scanf("%lf%lf%lf%d", &capacity, &distance, &avg_dis, &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lf%lf", &stations[i].avg_price, &stations[i].distance);
	}

	// 一次加满油，能跑的距离
	double dis = capacity * avg_dis;

	// 先对加油站进行排序，距杭州由近到远
	sort(stations, stations + N, cmp_pat_a1033);

	// 计算两个加油站/目的地之间的距离(起始点有加油站)
	for (int i = 0; i < N; ++i) {
		if (i < N - 1) { // 加油站之间的距离
			stations[i].bet_dis = stations[i + 1].distance - stations[i].distance;
		}
		else { // 最后一个加油站与目的地的距离
			stations[i].bet_dis = distance - stations[i].distance;
		}
	}

	// 判断是否能够到达目的地
	// 如果不能到达, 则两地之间加满油之后，都到不了
	bool flag = true; // 假设能到达
	int index = 0; // 记录第i个加油站不能到达下一个加油站(目的地)[0, N-1]
	double max_dis{ 0 }; // 记录最远能到的距离
	for (; index < N; ++index) {
		if (dis < stations[index].bet_dis) {
			flag = false;
			max_dis += dis;
			break;
		}
		max_dis += stations[index].bet_dis;
	}
	if (flag == true) { // 能够到达

	}
	else { // 不能到达
		printf("The maximum travel distance = %.2f", max_dis);
	}

}


//int main() {
//	pat_a1033();
//
//	return 0;
//}