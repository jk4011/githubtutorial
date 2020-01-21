#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

long long numTree, want;
long long list[MAX];

int bs(int tallest) {
	int start = 0;
	int end = tallest;
	int mid;
	
	while (start <= end) {
		mid = (start + end)/2;
		int sum=0;
		for (int i=0; i<numTree; i++)
			if (mid < list[i])
				sum += list[i] - mid;
		
		if (sum < want)
			end = mid-1;
		else if (sum >= want)
			start = mid+1;
	}
	return end;
}

int main() {
	cin >> numTree >> want;
	long long Max=0;
	for (int i=0; i<numTree; i++) {
		cin >> list[i];
		Max = max(Max, list[i]);
	}
	
	cout << bs(Max) << endl;
	
	
}
















