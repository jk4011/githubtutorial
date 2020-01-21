#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cir1[2000], cir2[2000];
int sum1[1000000], sum2[1000000];

int main() {
	int want, n, m;
	cin >> want >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> cir1[i];
		cir1[i+n] = cir1[i];
	}
	for (int i=0; i<m; i++) {
		cin >> cir2[i];
		cir2[i+m] = cir2[i];
	}
	for (int i=0; i<n; i++) {
		sum1[(n-1)*i] = cir1[i];
		for (int j=1; j<=n-2; j++) {
			sum1[(n-1)*i+j] = sum1[(n-1)*i+j-1] + cir1[i+j];
		}
	}
	for (int i=0; i<m; i++) {
		sum2[(m-1)*i] = cir2[i];
		for (int j=1; j<=m-2; j++) {
			sum2[(m-1)*i+j] = sum2[(m-1)*i+j-1] + cir2[i+j];
		}
	}
//	cout << endl << "cir1" << endl;
//	for (int i=0; i<n; i++)
//		cout << cir1[i] << ' ';
//	cout << endl;
//	cout << endl << "cir2" << endl;
//	for (int i=0; i<m; i++)
//		cout << cir2[i] << ' ';
//	cout << endl;
	if (n>=2)
		sum1[n*n-n] = sum1[n*n-n-1] + cir1[n-2];
	sum1[n*n-n+1] = 0;
	if (m>=2)
		sum2[m*m-m] = sum2[m*m-m-1] + cir2[m-2];
	sum2[m*m-m+1] = 0;
	sort(sum1, sum1+n*n-n+2);
	sort(sum2, sum2+m*m-m+2);
	
//	cout << endl << "sum1" << endl;
//	for (int i=0; i<n*n-n+2; i++)
//		cout << sum1[i] <<' ';
//	cout << endl;
//	cout << endl << "sum2" << endl;
//	for (int i=0; i<m*m-m+2; i++)
//		cout << sum2[i] <<' ';
//	cout << endl;
	
	int leng1 = n*n-n+2;
	int leng2 = m*m-m+2;
	
	int idx1 = 0, idx2 = 0;
	int ans = 0;
	for (int i=0; i<leng1; i++) {
		int high = upper_bound(sum2, sum2+leng2, want-sum1[i]) - sum2;
		int low = lower_bound(sum2, sum2+leng2, want-sum1[i]) - sum2;
		ans += high - low;
	}
	cout << ans;
	
}
