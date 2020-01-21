#include <list>
#include <iostream>
using namespace std;

int main() {
	list<int> l;
	int a=1 ,b=2, c=3, d=4, e=5;
	
	l.push_back(a);
	l.push_back(b);
	l.push_back(c);
	l.push_back(d);
	l.push_back(e);
	
	list<int>::iterator i = l.begin();
	list<int>::iterator j = l.begin();
	
	l.erase(i);
	cout << *j;
	
	return -111;
}
