#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> arr;
vector<int> psum;
vector<pair<int,int>> ret;
int nchild, ndoll;

void getPsum() {
	psum.resize(arr.size());
	psum[0]=0;
	for (int i=1; i<=ndoll; i++)
		psum[i] = psum[i-1] + arr[i];
}

void getRet() {
	for (int i=1; i<=ndoll; i++) {
		for (int j=0; j<i; j++) {
			if ((arr[i]-arr[j]) % nchild == 0)
				ret.push_back({j,i});
		}
	}
}

int greedy() {
	sort(ret.begin(), ret.end());
	int n=ret.size(), cnt=1, idx=ret[0].second;
	for (int i=1; i<n; i++) {
		if (idx > ret[i].second)
			idx = ret[i].second;
		else if (idx <= ret[i].first) {
			cnt++;
			idx = ret[i].second;
		}
	}
	return cnt;
}

int main() {
	int N;
	cin >> N;
	for (int i=0; i<N; i++) {

	arr.clear();
	psum.clear();
	ret.clear();	
		
	cin >> ndoll >> nchild;
	arr.resize(ndoll+1);
	arr[0] = 0;
	for (int i=1; i<=ndoll; i++)
		cin >> arr[i];
	getPsum();
	getRet();
	
//	for (auto i: ret)
//		cout << i.first << ' ' << i.second << endl;
	cout << ret.size() << ' ' << greedy() << endl;
	
	
	
	}
	
}


