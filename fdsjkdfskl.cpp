#include <list>
#include <iostream>
using namespace std;

int main() {
	list<int> a;
	list<int>::iterator b = --a.end();
	list<int>::iterator c = b;
	return 0;
}
