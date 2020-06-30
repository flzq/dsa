#include <iostream>
#include <string>
#include <map>
using namespace std;

void pat_a1071() {
	int max{ -1 };
	string sentence, max_word;
	map<string, int> m_words;
	getline(cin, sentence);
	int len_sent = sentence.size();
	// 先将所有大写字母转化为小写
	for (int i = 0; i < len_sent; ++i) {
		if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
			sentence[i] = sentence[i] - 'A' + 'a';
		}
	}
	int i = 0;
	while (i < len_sent) {
		if ((sentence[i] >= '0' && sentence[i] <= '9') || (sentence[i] >= 'a' && sentence[i] <= 'z')) {
			int j = i;
			while (j < len_sent && (sentence[j] >= '0' && sentence[j] <= '9') || (sentence[j] >= 'a' && sentence[j] <= 'z')) {
				++j;
			}
			if (m_words.find(sentence.substr(i, j - i)) != m_words.end()) {
				m_words[sentence.substr(i, j - i)] += 1;
			}
			else {
				m_words[sentence.substr(i, j - i)] = 1;
			}
			if (max < m_words[sentence.substr(i, j - i)]) {
				max = m_words[sentence.substr(i, j - i)];
				max_word = sentence.substr(i, j - i);
			}
			i = j;
		}
		else {
			++i;
		}
	}
	cout << max_word << " " << max;
}

//int main() {
//	pat_a1071();
//	return 0;
//}