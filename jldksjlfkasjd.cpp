#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 1000000;
unsigned char seive[MAX];

inline bool isPrime(int k) {
	return seive[k>>3] & (1<<(7&k));
}

inline void setComposite(int k) {
	seive[k >> 3] &= ~(1<<(7&k));
}

void erastosthenes() {
	memset(seive, 255, sizeof(seive));
	setComposite(0);
	setComposite(1);
//	int sqrtn = int(sqrt(n));
//	for (int i=2; i<=sqrtn; i++) {
//		
//	}
}

int main() {
	cout << sqrt(11);
}
