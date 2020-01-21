#include <iostream>
using namespace std;

const int MAX = 10000;

int arr[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, want, cnt=0;
	cin >> N >> want;
	for (int i=0; i<N; i++)
		cin >> arr[i];
	int sum = arr[0];
	
	int low=0, high=0;
	while (high>=low && high<N) {
		if (want > sum)
			sum += arr[++high];
		
		else if (want == sum) {
			cnt++;	
			sum += arr[++high];
		}
			
		else if (want < sum) {
			sum -= arr[low++];
			if (low > high && low<N) {
				sum = arr[low];
				high = low;
			}
		}
		
	}
	cout << cnt;
	
	
	
}
