#include <iostream>
#include <time.h>
using namespace std;

int main() {
	time_t start, end;
	string input;
	double dif;
	time(&start);
	cin >> input;
	time(&end);
	cout << end << ' ' << start << endl;
	cout << end - start;
}
