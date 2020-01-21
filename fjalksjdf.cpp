#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
//#define MAX
using namespace std;

int count(int n) {
	if (n==1)
		return 1;
		
	return count(n-1)*2 + 1;
}

void hanoi(int n, int prev, int next) {
	if (n==0) {
		return;
	}
	hanoi(n-1, prev, 6-prev-next);
	cout << prev << ' ' << next << endl;
	hanoi(n-1, 6-prev-next, next);
}


int main() {
	int n;
	cin >> n;
	cout << count(n) << endl;
	hanoi(n, 1, 3);
}
