#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int list[100001];
int n, cnt=999999, want;

void DFS(int now, int sum, int depth) {
	sum += list[now];
	if (sum==want)
		cnt = min(cnt, depth);
	if (sum>=want || now==n-1 || depth >= cnt)
		return;
	
	DFS(now+1, sum, depth+1);
}

int main() {
	cin >> n >> want;
	for (int i=0; i<n; i++) {
		cin >> list[i];
	}
	
	for (int i=0; i<n; i++) {
		DFS(i, 0, 1);
	}
	cout << cnt;
}
