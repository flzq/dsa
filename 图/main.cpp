#include <string>
#include <vector>
#include <iostream>
#include "MGraph.h"
#include "LGraph.h"
using namespace std;

void test_graph() {
	int M;
	string n1, n2;
	MGraph g{ true };
	cin >> M;
	while (M--) {
		cin >> n1 >> n2;
		g.insert_edge(n1, n2);
	}
	g.print();
	cout << "-----" << endl;
	cout << g.top_sort() << endl;
}

int main() {
	test_graph();
}