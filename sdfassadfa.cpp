#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n, m;
vector<int> graph[10001];
int H[10001];

void height(int node) {
	int Max = 0;
	for (auto i: graph[node]) {
		if (!H[i])
			height(i);
		Max = max(Max, H[i]);
	}
	H[node] = Max+1;
}

int main() {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		graph[b].push_back(a);
	}
	int ans = 0;
	for (int i=1; i<=n; i++) {
		if (!H[i])
			height(i);
	}
	int Max = 0;
	for (int i=1; i<=n; i++)
		Max = max(Max, H[i]);
	for (int i=1; i<=n; i++)
		if (Max == H[i])
			cout << i << ' ';
}
