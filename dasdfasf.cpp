#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int N, want;
int arr[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int sum=0;
	cin >> N >> want;
	for (int i=0; i<N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum < want) {
		cout << 0;
		return 0;
	}
	int ans = 9999999;
	int low=0, high=0;
	sum = arr[0];
	
	while (high>=low && high<N) {
		if (sum<want) {
			sum += arr[++high];
		}
		else if (sum>=want) {
//			if (high-low+1==1 && ans != 1)
//				cout << sum << ' ' << low << ' '<< high << endl;
			ans = min(ans, high-low+1);
			sum -= arr[low++];
			
			if (low>high && low<N) {
				sum = arr[low];
				high = low;
			}
		}
	}
	cout << ans;
	
}










