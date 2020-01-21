#include <iostream>
#include <string>
using namespace std;

int Min(int a, int b) {
	return (a<b? a:b);
}

int Max(int a, int b) {
	return (a>b? a:b);
}

int main() {
	int n;
	cin >> n;
	
	int num = 1, test = n;
	while (test) {
		test /= 10;
		num++;
	}
	
	cout << num;
	
	
	
	
	
	
	
	return 0;
}

