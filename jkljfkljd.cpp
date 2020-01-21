#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int n_ = 5e4 + 3;

int n, m;
int dph[n_], pnt[n_];
vector<int> gph[n_];

inline void dfs(int now, int cnt) {
	dph[now] = cnt++;
	for (auto nxt : gph[now]) {
		if (!dph[nxt]) dfs(nxt, cnt), pnt[nxt] = now;
	}
}

int main() {
	int a, b, i;
	scanf("%d", &n);
	while (--n) {
		scanf("%d %d", &a, &b);
		gph[a].push_back(b);
		gph[b].push_back(a);
	}
	dfs(1, 1);
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		if (dph[a] < dph[b]) swap(a, b);
		while (dph[a] != dph[b]) a = pnt[a];
		while (a != b) a = pnt[a], b = pnt[b];
		printf("%d\n", a);
	}
	return 0;
}
