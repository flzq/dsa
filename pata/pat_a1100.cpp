#include <iostream>
#include <vector>
#include <string>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::map;
using std::vector;

void pat_b1044() {
	int N;
	string s_num;
	map<string, int> m_ge; // ��λӳ��
	map<string, int> m_shi; // ��λӳ��
	/*
	�����˵� 0 �������˳�Ϊ tret��
	���������� 1 �� 12 �Ļ����ķֱ�Ϊ��jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec��
	�����˽���λ�Ժ�� 12 ����λ���ֱַ��Ϊ��tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou
	*/
	m_ge["tret"] = 0, m_ge["jan"] = 1, m_ge["feb"] = 2, m_ge["mar"] = 3, m_ge["apr"] = 4, m_ge["may"] = 5, m_ge["jun"] = 6, m_ge["jly"] = 7, m_ge["aug"] = 8, m_ge["sep"] = 9, m_ge["oct"] = 10, m_ge["nov"] = 11, m_ge["dec"] = 12;
	m_shi["tam"] = 1, m_shi["hel"] = 2, m_shi["maa"] = 3, m_shi["huh"] = 4, m_shi["tou"] = 5, m_shi["kes"] = 6, m_shi["hei"] = 7, m_shi["elo"] = 8, m_shi["syy"] = 9, m_shi["lok"] = 10, m_shi["mer"] = 11, m_shi["jou"] = 12;
	vector<string> v_ge{ "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	vector<string> v_shi{ "tmp","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	cin >> N;
	cin.get(); // ���Ļس�

	for (int i = 0; i < N; ++i) {
		getline(cin, s_num);
		if (s_num[0] >= '0' && s_num[0] <= '9') { // ʮ��������תʮ�����ƻ�����
			int num{ 0 };
			// ���10������
			for (int i = 0; i < s_num.size(); ++i) {
				num = num * 10 + s_num[i] - '0';
			}
			if (num >= 13) {
				cout << v_shi[num / 13];
				num = num % 13;
				if (num) {
					cout << " " << v_ge[num];
				}
				cout << endl;
			}
			else {
				cout << v_ge[num] << endl;
			}
		}
		else { // ������תʮ����
			int index = s_num.find(" ");
			if (index == string::npos) {
				if (m_ge.find(s_num) != m_ge.end()) {
					cout << m_ge[s_num] << endl;
				}
				else {
					cout << m_shi[s_num] * 13 << endl;
				}
			}
			else {
				int shi = m_shi[s_num.substr(0, index)];
				int ge = m_ge[s_num.substr(index + 1, s_num.size() - index - 1)];
				int num = shi * 13 + ge;
				cout << num << endl;
			}

		}
	}

}

//int main() {
//	pat_b1044();
//	return 0;
//}