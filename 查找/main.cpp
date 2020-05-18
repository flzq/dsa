#include <iostream>
#include "HashTable.h"


void test_hashtable() {
	HashTable ht{ 12 };
	ht.insert(13);
	ht.insert(1);
	ht.insert(2);
	ht.insert(8);
	ht.insert(24);
	ht.insert(33);
	ht.insert(0);
	ht.print();
	ht.remove(13);
	ht.print();
	std::cout << ht.find(13) << std::endl;
	std::cout << ht.find(3) << std::endl;
	std::cout << ht.find(24) << std::endl;
	std::cout << "===========" << std::endl;
	ht.insert(13);
	ht.print();
	std::cout << ht.find(13) << std::endl;
}



int main() {
	// test_hashtable();

	return 0;
}