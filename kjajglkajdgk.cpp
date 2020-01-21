#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

bool isPrime[10000];
bool connect[1061][1061];
vector<int> primes;

int bs(int want) {
	int start = 0;
	int end = primes.size()-1;
	while (end>=start) {
		int mid = (end+start)/2;
		if (primes[mid] == want)
			return mid;
		if (primes[mid] > want)
			end = mid-1;
		if (primes[mid] < want)
			end = mid-1;
	}
	return -1;
}

void checkPrime(int n) {
	int p = primes[n];
	for (int i=0; i<primes.size(); i++) {
		primes[i];
	}
	int one = p -(p%10);
	int ten = p -(p%100 - p%10);
	int hun = p -(p%1000 - p%100);
	int thou = p % 1000;
	for (int i=0; i<10; i++) {
		if (isPrime(one + i)) {
			connect()
		}
		if (isPrime(ten+ i*10))
		if (isPrime(hun+ i*100))
		if (isPrime(thou+ i*1000))
	}
}

int main() {
	memset(isPrime, 1, sizeof(isPrime));
	for (int i=2; i<100; i++) {
		for (int j=2; i*j<10000; j++)
			isPrime[i*j] = 0;
	}
	for (int i=1000; i<10000; i++) {
		if (isPrime[i])
			primes.push_back(i);
	}
	int n;
	cin >> n;
	
	for (int i=0; i<n; i++) {
		int a,b;
		cin >> a >> b;
		cout << BFS(a, b);
	}
	








