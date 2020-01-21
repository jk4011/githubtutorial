#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 26
using namespace std;

bool visited[MAX][MAX];
bool graph[MAX][MAX];
int cnt;

void DFS(int x, int y) {
	visited[x][y] = true;
	cnt++;
//	cout << x << ' ' << y << endl;
	if (!visited[x+1][y] && graph[x+1][y]) {
		DFS(x+1, y);
	}
	if (x>1 && !visited[x-1][y] && graph[x-1][y]) {
		DFS(x-1, y);
	}
	if (!visited[x][y+1] && graph[x][y+1]) {
		DFS(x, y+1);
	}
	if (y>1 && !visited[x][y-1] && graph[x][y-1]) {
		DFS(x, y-1);
	}
}


int main() {
	vector<int> ans;
	
	int n;
	cin >> n;
	
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			char x;
			cin >> x;
			graph[i][j] = x - '0';
		}
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (!visited[i][j] && graph[i][j]) {
				cnt = 0;
				DFS(i, j);
				ans.push_back(cnt);
			}
		}
	}
	
	sort(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
	
	for (int i=0; i<ans.size(); i++)
		cout << ans[i] << endl;
	
	
	
	
	
}
