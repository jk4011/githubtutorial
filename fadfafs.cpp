#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr1[1000], arr2[1000];
vector<int> sum1, sum2;

int main() {
	int want, n, m;
	cin >> want >> n;
	for (int i=0; i<n; i++)
		cin >> arr1[i];
	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> arr2[i];
	}
	
	for (int i=0; i<n; i++) {
		sum1.push_back(arr1[i]);
		for (int j=1; j<(n-i); j++) {
			sum1.push_back(arr1[i+j]+sum1.back());
		}
	}
	for (int i=0; i<m; i++) {
		sum2.push_back(arr2[i]);
		for (int j=1; j<(m-i); j++) {
			sum2.push_back(arr2[i+j]+sum2.back());
		}
	}
	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());
	
//	int leng1 = sum1.size();
//	int leng2 = sum2.size();
//	cout << endl << "sum1" << endl;
//	for (int i=0; i<leng1; i++)
//		cout << sum1[i] <<' ';
//	cout << endl;
//	cout << endl << "sum2" << endl;
//	for (int i=0; i<leng2; i++)
//		cout << sum2[i] <<' ';
//	cout << endl << endl;
	
	
	int idx1 = 0, idx2 = 0;
	long long ans = 0;
	for (int i=0; i<sum1.size(); i++) {
		int high = upper_bound(sum2.begin(), sum2.end() ,want-sum1[i]) - sum2.begin();
		int low = lower_bound(sum2.begin(), sum2.end() ,want-sum1[i]) - sum2.begin();
//		cout << high << ' ' << low << endl;
		ans += high-low;
	}
	cout << ans;
	
}
