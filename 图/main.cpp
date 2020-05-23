#include <string>
#include <vector>
#include <iostream>
#include "MGraph.h"
#include "LGraph.h"
using namespace std;

void test_graph() {
	int M, d;
	string n1, n2;
	MGraph g{ true };
	cin >> M;
	while (M--) {
		cin >> n1 >> n2 >> d;
		g.insert_edge(n1, n2, d);
	}
	g.weighted_shortest_path("A");
}

int main() {
	test_graph();
}