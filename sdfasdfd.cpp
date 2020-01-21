#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <tuple>
using namespace std;

const int MAX = 100;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int W, H;
bool graph[MAX][MAX];
bool visited[MAX][MAX];

int BFS() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0, {0, 0} });
    visited[0][0] = true;
	
	while(!pq.empty()) {
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int block = pq.top().first;
		pq.pop();
//		cout << x << ' ' << y << ' ' << block << endl;
		
		if (y==H-1 && x==W-1) {
			return block;
		}
		
		for (int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (0 > ny || ny >= H || 0 > nx || nx >= W)
				continue;
			
			if (!visited[ny][nx]) {
				if (graph[ny][nx]==1) {
					pq.push({block+1,{ny,nx}});
				}
				else
					pq.push({block,{ny,nx}});
				visited[ny][nx] = true;
			}
		}
		
		
	}
	
	
}






int main() {
	cin >> W >> H;
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			char x;
			cin >> x;
			graph[i][j] = x-'0';
		}
	}
	
	cout << BFS();
    return 0;
}

