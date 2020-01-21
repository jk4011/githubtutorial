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

const int MAX = 100003;

int depth[MAX] = {0,0,};
vector<int> graph[MAX];
int parent[MAX] = {0,0,};

inline void dfs(int node, int cnt) {
	depth[node] = cnt;
	for (auto i: graph[node]) {
		if (depth[i] == 0) {
			dfs(i, cnt+1);
			parent[i] = node;
		}
	}
}


int main() {
	int n;
	cin >> n;
	cout << n << endl;
	for (int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1,1);
	int m;
	cin >> m;
	for (int i=0; i<m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		if (depth[n1] < depth[n2])
			swap(n1, n2);
		while (depth[n1] != depth[n2]) {
			n1 = parent[n1];
		}
		while (n1 != n2) {
			n1 = parent[n1];
			n2 = parent[n2];
		}
		cout << n1 << endl;
		}
}








