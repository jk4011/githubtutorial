#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int INF = 987654321;

vector<int> button[10] = {
{0,1,2},
{3,7,9,11},
{4,10,14,16},
{0,4,5,6,7},
{6,7,8,10,12},
{0,2,14,15},
{3,14,15},
{4,5,7,14,15},
{1,2,3,4,5},
{3,4,5,9,13},
};

int Min = INF;

int totalSwitch(int count, int clock[16], int now) {
	if (count > Min)	
		return INF;
	
	bool ok = true;
	for (int i=0; i<16; i++) {
		if (clock[i] != 0)
			ok = false;
	}
	if (ok) {
		Min = count;
		return count;
	}
	
	int ret = INF;
	for (int j=now; j<16; j++) {
		for (auto i: button[j]) {
			clock[i]++;
			clock[i] %= 4;
		}
		ret = min(ret, totalSwitch(count+1, clock, j));
		for (auto i: button[j]) {
			clock[i] += 3;
			clock[i] %= 4;
		}
	}
	return ret;
}

int main() {
	int clock[16];
	for (int i=0; i<16; i++) {
		cin >> clock[i];
		clock[i] /= 3;
	}
	cout << totalSwitch(0, clock, 0);
}
