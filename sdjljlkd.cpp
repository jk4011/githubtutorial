#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int x;
int cache[2][2][2];


int f() {
	int &x = cache[0][0][0];
	x += 1;
	return x;
}

int main() {
	cache[0][0][0] = 1;
	cout << f();
	cout << x;
}
