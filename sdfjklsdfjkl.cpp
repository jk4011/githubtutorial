#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> a;
	a.push_back(7);
	a.push_back(6);
	a.push_back(5);
	a.push_back(4);
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	
	for (list<int>::iterator i = a.begin(); i != a.end(); i++) {
		cout << *i << endl;
	}
}
