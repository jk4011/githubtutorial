#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;


	int a[1000001];//구해져 있다 가정; 

int main() {
	
	
	for (int i=1; i<=1000000; i++) {
		a[i] = 1;
	}
	
	for (int i=2; i*i<1000000; i++) {
		if (a[i]==1) {
			for (int j=2; i*j<=1000000; j++) {
				a[i*j] = 0;
			}
		}
	}
	int n;
	cin >> n;
	int x;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (x==0)
			break;
		for (int j=3; j<=x/2; j+=2) {
			if (a[j]&&a[x-j]) {
				cout << x << " = " << j << " + " << x-j << endl;
				break;
			}
				
			else if (j==x/2)
				cout << "Goldbach's conjecture is wrong." << endl;
		}
	}
	
}

