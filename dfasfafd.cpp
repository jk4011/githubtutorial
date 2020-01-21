#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int list[20000];
	for (int i=0; i<n; i++) {
		int N;
		cin >> N;
		int leng = 9999999;
		
		for (int j=0; j<N; j++) {
			cin >> list[j];
			for (int k=max(0,j-leng-1); k<j; k++) {
				if (list[k] == list[j])
					leng = j-k+1;
			}
		}
		if (leng == 9999999)
			cout << -1 << endl;
		else
			cout << leng << endl;
		
	}
	
}
