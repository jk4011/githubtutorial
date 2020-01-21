#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

int graph[300000];
int visit[300000];
int order[300000];


int ans;

int sum(int x,int t) {
	int s = 0;
	while (x) {
		s += pow(x%10, t);
		x /= 10;
	}
	return s;
}

void dfs(int v, int t) {
//	cout << v << endl;
	if (!visit[v]) {
		ans ++;
//		cout << ans << endl;
		visit[v] = 1;
		graph[v] = sum(v,t);
		order[v] = ans;
		dfs(sum(v,t), t);
	}
	else {
		cout << order[v]-1;
	}
}

int main() {
	int v, t;
	cin >> v >> t;
	dfs(v,t);
//	cout << ans;
}
