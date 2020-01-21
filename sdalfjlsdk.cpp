#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> psum; // 나머지 값이 들어있음 

int waysToBuy(const vector<int>& psum, int k) {
	int ret = 0;
	vector<long long> count(k, 0); //값이 0인걸 k개 생성
	for (int i=0; i < psum.size(); i++) {
		count[psum[i]]++;
	}
	for (int i=0; i<k; i++) {
		if (count[i] >= 2)
			ret += (count[i]) * (count[i]-1)/2;
	} 
	return ret;
}

int maxBuys(const vector<int>& psum, int k) {
	vector<int> ret(psum.size(), 0);
	vector<int> prev(k, -1);
	for (int i=0; i<psum.size(); i++) {
		if (i>0)
			ret[i] = ret[i-1];
		else
			ret[i] = 0;
		cout << ret[i] << ' ';
		int loc = prev[psum[i]];
		if(loc != -1)
			ret[i] = max(ret[i], ret[loc] + 1);
		prev[psum[i]] = i;
		cout << ret[i] << endl;
	}
	return ret.back();
}

int main() {
	psum.resize(4);
	psum = {1,1,0,0};
	cout << maxBuys(psum, 2);
}



