#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;



int main() {
	map<string, int> m;
	
	long long N;
	string x;
	
	cin >> N;
	
	
	for (long long i=0; i<N; i++) {
		cin >> x;
		m[x]++;
	}
	
	for (long long i=0; i<N-1; i++) {
		cin >> x;
		m[x]++;
	}
	
	for (auto a:m) {
		if (a.second%2 == 1) {
			cout << a.first << endl;
			break;
		}
	}
}
