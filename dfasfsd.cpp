#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int N, want;
int arr[40];






int main() {
	cin >> N >> want;
	for (int i=0; i<N; i++)
		cin >> arr[i];
	sort(arr, arr+N);
	
	int low=0, high=0;
	int cnt=0;
	int sum = arr[0];
	
	while (high>=low && high<N) {
		if (sum > want) {
			sum += arr[++high];
		}
		
		else if (sum == want) {
			cout << high << ' ' << low << endl;
			sum += arr[++high];
			cnt++;
		}
		
		else if (sum < want) {
			sum -= arr[low++];
			if (low > high && low<N) {
				high = low;
				sum = arr[low];
			}
		}
	}
	cout << cnt;
}











