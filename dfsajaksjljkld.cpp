#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int graph[21][21];
bool visited[27];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int ans;
int R, C;

void DFS(int y, int x, int cnt) {
	ans = max(ans, cnt);
	
	for (int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny<0 || ny>=R || nx<0 || nx>=C)
			continue;
		
		int k=graph[ny][nx];
		if (visited[k])
			continue;
		
		visited[k] = true;
		DFS(ny,nx,cnt+1);
		visited[k] = false;
	}
}

int main() {
	cin >> R >> C;
	
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			char x;
			cin >> x;
			graph[i][j] = x - 'A';
		}
	}
	visited[graph[0][0]] = 1;
	DFS(0,0,1);
	cout << ans << endl;
}




