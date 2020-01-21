#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int leng[1001];
	for (int i=0 ;i<n; i++) {
		for (int i=1; i<1001; i++)
			leng[i]=0;
		int x;
		cin >> x;
		for (int i=1; i<=x; i++) {
			int y;
			cin >> y;
			for (int j=1; j<=y; j++) {
				leng[j]++;
			}
		}
		int max = 0;
		for (int i=1; i<1001; i++) {
			if (leng[i] >= i)
				max=i;
		}
		cout << max << endl;
	}
}
