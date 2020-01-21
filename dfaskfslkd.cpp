#include <iostream>
#include <set>
#include <vector> 
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

const int MAX = 401;
int adj[MAX][MAX];

void floyd(int V) {
	for (int k=1; k<=V; k++) {
		for (int i=1; i<=V; i++) {
			for (int j=1; j<=V; j++)
				if (adj[i][j] == INF)
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
		}
	}
}

int main() {
	int V, n;
	cin >> V >> n;
	for (int i=1; i<=V; i++) {
		for (int j=1; j<=V; j++)
			adj[i][j] = INF;
	}
	for (int i=1; i<=n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1][n2] = 1;
	}
	cin >> n;
	for (int i=1; i<=n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		if (adj[n1][n2] < INF)
			cout << -1 << endl;
		else if (adj[n2][n1] < INF)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}
