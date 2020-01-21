#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
#define MAX 100
using namespace std;

int H, W, ans;
int graph[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void DFS() {
	dist[0][0] = 0;
	queue<pair<int,int>> q;
	q.push({0,0});
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
//		cout << x+1 << ' ' << y+1 << endl;
		for (int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (0>ny || 0>nx || W<=nx || H<=ny)
				continue;
			
			if (graph[ny][nx] == 1) {
				if (dist[ny][nx] > dist[y][x]+1) {
					dist[ny][nx] = dist[y][x]+1;
					q.push({ny,nx});
				}
			}
			
			if (graph[ny][nx] == 0) {
				if (dist[ny][nx] > dist[y][x]) {
					dist[ny][nx] = dist[y][x];
					q.push({ny,nx});
				}
			}
		}
		
	}
}



int main() {
	ans = 987654321;
	cin >> W >> H;
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			char x;
			cin >> x;
			graph[i][j] = x-'0';
			dist[i][j] = 987654321;
		}
	}
	
	DFS();
	cout << dist[H-1][W-1];
}








