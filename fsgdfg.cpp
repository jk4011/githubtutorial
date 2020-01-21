#include <iostream>
#include <algorithm>
#define MAX 200001
#define ll long long

using namespace std;

ll house[MAX];
long long distan[MAX-1];
ll numSpot;

ll bs(ll n) {
	ll start = 1;
	ll end = (house[n-1]-house[0])/(numSpot-1);
	
	while (start <= end) {
		ll mid = (start+end)/2;
		ll sum=0;
		ll numSpot2=1;
		for (ll i=0; i<n-1; i++) {
			sum += distan[i];
			if (sum >= mid) {
				sum = 0;
				numSpot2++;
			}
		}
		if (numSpot2 >= numSpot) {
			start = mid + 1;
		}	
		else if (numSpot2 < numSpot) {
			end = mid - 1;
		}
	}
	return end;
}

int main() {
	ll n;
	cin >> n;
	cin >> numSpot;
	
	cin >> house[0];
	for (ll i=1; i<n; i++) {
		cin >> house[i];
	}
	sort(house, house+n);
	
	for (ll i=0; i<n-1; i++) {
		distan[i] = house[i+1] - house[i];
	}
	
	cout << bs(n);
//	bs(n);	
	
	
}
































