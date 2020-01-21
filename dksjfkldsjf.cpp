#include <iostream>
using namespace std;

const int MAX = 401;
int adj[MAX][MAX];
int V, n;

void floyd() {
	for (int k=1; k<=V; k++) {
		for (int i=1; i<=V; i++) {
			for (int j=1; j<=V; j++) {
                if(i==j ||j==k ||i==k)
                    continue;
                if (adj[i][j]==0) {
					if (adj[i][k] == 1 && adj[k][j] == 1)
						adj[i][j] = 1;
					else if (adj[i][k] == -1 && adj[k][j] == -1)
						adj[i][j] = -1;
				}
			}
		}
	}
}

int main() {
	cin >> V >> n;
	for (int i=1; i<=n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1][n2] = -1;
		adj[n2][n1] = +1;
	}
	floyd();
	cin >> n;
	for (int i=1; i<=n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << adj[n1][n2] << endl;
	}
}








