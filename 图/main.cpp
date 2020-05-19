#include <string>
#include <vector>
#include <iostream>
#include "MGraph.h"
#include "LGraph.h"
using namespace std;

void test_graph() {
	vector<string> v{ "AA", "CC", "BB" };
	LGraph g2(v, true);


	g2.insert_edge("AA", "CC");
	g2.insert_edge("CC", "BB", 66);
	g2.insert_edge("XX", "OO");
	g2.insert_edge(0, 3, 88);;
	g2.print();
	cout << "AA--CC: " << g2.find_edge("AA", "CC") << endl;
	cout << "AA--XX: " << g2.find_edge("AA", "XX") << endl;
	cout << "1--2: " << g2.find_edge(1, 2) << endl;
	cout << "0--2: " << g2.find_edge(0, 2) << endl;

	/*LGraph lg(v);
	lg.print();*/
}

int main() {
	test_graph();
}