#include <iostream>
#include <map>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

void pat_a1054() {
	int M, N, max{ -1 };
	string color;
	string max_color;
	map<string, int> m_colors;
	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> color;
			if (m_colors.find(color) != m_colors.end()) {
				int tmp_max = m_colors[color] + 1;
				m_colors[color] = tmp_max;
				if (max < tmp_max) {
					max = tmp_max;
					max_color = color;
				}
			}
			else {
				m_colors[color] = 1;
				if (max < 1) {
					max = 1;
					max_color = color;
				}
			}
		}
	}
	cout << color;

}

//int main() {
//	pat_a1054();
//	return 0;
//}