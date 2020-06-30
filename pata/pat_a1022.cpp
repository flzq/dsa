#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

void pat_a1022() {
	int N, M;
	string id, book, author, publisher, pub_year, query, keys;
	map<string, set<string>> mm_book_names;
	map<string, set<string>> mm_authors;
	map<string, set<string>> mm_keywords;
	map<string, set<string>> mm_publishers;
	map<string, set<string>> mm_years;
	cin >> N;
	cin.get();
	for (int i = 0; i < N; ++i) {
		getline(cin, id);
		getline(cin, book);
		getline(cin, author);
		while (cin >> keys) {
			mm_keywords[keys].insert(id);
			char c = getchar();
			if (c == '\n') {
				break;
			}
		}
		getline(cin, publisher);
		getline(cin, pub_year);
		mm_book_names[book].insert(id);
		mm_authors[author].insert(id);
		mm_publishers[publisher].insert(id);
		mm_years[pub_year].insert(id);
	}
	cin >> M;
	cin.get();
	for (int i = 0; i < M; ++i) {
		getline(cin, query);
		string query_word = query.substr(3, query.size() - 3);
		cout << query << endl;
		if (query[0] == '1') { // ������������
			if (mm_book_names.find(query_word) != mm_book_names.end()) {
				for (set<string>::iterator it = mm_book_names[query_word].begin(); it != mm_book_names[query_word].end(); ++it) {
					cout << *it << endl;
				}
			}
			else {
				cout << "Not Found" << endl;
			}
		}
		else if (query[0] == '2'){ // �������߲���
			if (mm_authors.find(query_word) != mm_authors.end()) {
				for (set<string>::iterator it = mm_authors[query_word].begin(); it != mm_authors[query_word].end(); ++it) {
					cout << *it << endl;
				}
			}
			else {
				cout << "Not Found" << endl;
			}
		}
		else if (query[0] == '3') { // ���չؼ��ֲ���
			if (mm_keywords.find(query_word) != mm_keywords.end()) {
				for (set<string>::iterator it = mm_keywords[query_word].begin(); it != mm_keywords[query_word].end(); ++it) {
					cout << *it << endl;
				}
			}
			else {
				cout << "Not Found" << endl;
			}
		}
		else if (query[0] == '4') { // ���ճ��������
			if (mm_publishers.find(query_word) != mm_publishers.end()) {
				for (set<string>::iterator it = mm_publishers[query_word].begin(); it != mm_publishers[query_word].end(); ++it) {
					cout << *it << endl;
				}
			}
			else {
				cout << "Not Found" << endl;
			}
		}
		else if (query[0] == '5') { // ������ݲ���
			if (mm_years.find(query_word) != mm_years.end()) {
				for (set<string>::iterator it = mm_years[query_word].begin(); it != mm_years[query_word].end(); ++it) {
					cout << *it << endl;
				}
			}
			else {
				cout << "Not Found" << endl;
			}
		}
	}
}


//int main() {
//	pat_a1022();
//	return 0;
//}