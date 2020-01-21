#include <iostream>
#include <string>
using namespace std;


int main() {
	int a[100001];
	int N, M;
	cin >> N;
	cin >> M;
	a[1] = 1;
	a[2] = 1;
	for (int i=3; i<100001; i++) {
		a[i] = (a[i-1] + a[i-2]) % M;
	}
	
	int n;
	for (int i=0; i<N; i++) {
		cin >> n;
		cout << a[n] << endl;
	}
}
