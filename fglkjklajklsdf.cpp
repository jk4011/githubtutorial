#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

long long numPrev, numAft, l[10001], Max, mid;

long long bs(long long start, long long end) {
	while (start<=end) {
		mid = (start+end)/2;
		long long total = 0;
		
		for (int i=0; i<numPrev; i++)
			total += l[i]/mid;
		
		if (total>=numAft)
			start = mid+1;
		else if (total<numAft)
			end = mid-1;
	}
	return end;
}

int main() {
	cin >> numPrev >> numAft;
	for (int i=0; i<numPrev; i++) {
		cin >> l[i];
		Max = max(l[i], Max);
	}
	cout << bs(0, Max) << endl;
}






















