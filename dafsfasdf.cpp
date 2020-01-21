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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> want;
	for (int i=0; i<N; i++)
		cin >> arr[i];
	sort(arr, arr+N);
	
	int half = N/2;
	int numSubset = 1<<(N-half);
	
	vector<int> first(numSubset);
	for (int i=0; i < numSubset; i++)
		for (int j=0; j< N-half; j++)
			if (i&(1<<j))
				first[i] += arr[j];
				
	int numSubset2 = 1<<half;
	vector<int> second(numSubset2);
	for (int i=0; i < numSubset; i++)
		for (int j=0; j< half; j++)
			if (i&(1<<j))
				second[i] += arr[j+N-half];
	
	sort(first.begin(),first.end());
	sort(second.begin(),second.end(), greater<int>());
	
	int idx1=0, idx2=0;
	int result=0;
	while (idx1<numSubset && idx2<numSubset2) {
		if (first[idx1]+second[idx2] == want) {
			int cnt1=1, cnt2=1;
			idx1++; idx2++;
			while (idx1<numSubset && first[idx1]==first[idx1-1]) {
				idx1++;
				cnt1++;
			}
			while (idx2<numSubset2 && second[idx2]==second[idx2-1]) {
				idx2++;
				cnt2++;
			}
			result += cnt1*cnt2;
		}
		else if (first[idx1]+second[idx2] < want) {
			idx1++;
		}
		else if (first[idx1]+second[idx2] > want) {
			idx2++;
		}
	}
	
	if (want==0)
		result--;
	cout << result << endl;
}










