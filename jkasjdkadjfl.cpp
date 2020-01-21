#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 200;
int want[MAX];
int put[MAX];
int unit[MAX];

int gcd(int a, int b) {
	if (b==0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int N;
	cin >> N;
	
	for (int i=0; i<N; i++) {
		int n;
		cin >> n;
		for (int j=0; j<n; j++) {
			cin >> want[j];
		}
		for (int j=0; j<n; j++) {
			cin >> put[j];
		}
		int gcd_all = want[0];
		for (int j=1; j<n; j++) {
			gcd_all = gcd(gcd_all, want[j]);
		}
		for (int j=0; j<n; j++) {
			unit[j] = want[j] / gcd_all;
		}
		int numUnit=0;
		for (int j=0; j<n; j++) {
			int compare = (put[j]-want[j]+unit[j]-1) / unit[j];
			numUnit = max(numUnit, compare);
//		cout << compare << ' '<< numUnit <<endl;
		}
		int ans = 0;
		for (int j=0; j<n; j++) {
			cout << want[j]+numUnit*unit[j]-put[j] << ' ';
		}
		cout << endl;
	}
	
}







