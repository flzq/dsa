#include <string>
#include <vector>
#include <iostream>
#include "MGraph.h"
#include "LGraph.h"
using namespace std;

void test_graph() {
	vector<string> v{ "AA", "CC", "BB" };
	MGraph g1(5);
	MGraph g2(v);

	g2.print();
	std::cout << std::endl;
	g2.insert_edge("AA", "CC");
	g2.insert_edge("CC", "BB", 66);
	g2.insert_edge("XX", "OO");
	g2.insert_edge(0, 3, 88);;
	g2.print();

	/*LGraph lg(v);
	lg.print();*/
}

int main() {
	test_graph();
}