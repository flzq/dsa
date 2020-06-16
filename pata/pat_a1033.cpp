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
	// ��������
	scanf("%lf%lf%lf%d", &capacity, &distance, &avg_dis, &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lf%lf", &stations[i].avg_price, &stations[i].distance);
	}

	// һ�μ����ͣ����ܵľ���
	double dis = capacity * avg_dis;

	// �ȶԼ���վ�������򣬾ຼ���ɽ���Զ
	sort(stations, stations + N, cmp_pat_a1033);

	// ������������վ/Ŀ�ĵ�֮��ľ���(��ʼ���м���վ)
	for (int i = 0; i < N; ++i) {
		if (i < N - 1) { // ����վ֮��ľ���
			stations[i].bet_dis = stations[i + 1].distance - stations[i].distance;
		}
		else { // ���һ������վ��Ŀ�ĵصľ���
			stations[i].bet_dis = distance - stations[i].distance;
		}
	}

	// �ж��Ƿ��ܹ�����Ŀ�ĵ�
	// ������ܵ���, ������֮�������֮�󣬶�������
	bool flag = true; // �����ܵ���
	int index = 0; // ��¼��i������վ���ܵ�����һ������վ(Ŀ�ĵ�)[0, N-1]
	double max_dis{ 0 }; // ��¼��Զ�ܵ��ľ���
	for (; index < N; ++index) {
		if (dis < stations[index].bet_dis) {
			flag = false;
			max_dis += dis;
			break;
		}
		max_dis += stations[index].bet_dis;
	}
	if (flag == true) { // �ܹ�����

	}
	else { // ���ܵ���
		printf("The maximum travel distance = %.2f", max_dis);
	}

}


//int main() {
//	pat_a1033();
//
//	return 0;
//}