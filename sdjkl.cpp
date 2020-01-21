#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	
	list<int>::iterator i = L.begin();
	list<int>::iterator j = L.end();
	
	for (; i!=j; i++)
		cout << *i;
	
}
