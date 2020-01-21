#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> a;
	a.push_back(1);
	
	for (list<int>::iterator i= a.begin(); i!=a.end(); i++) {
		cout << *i;
	}
	
	
	
	
	
	
	
}
