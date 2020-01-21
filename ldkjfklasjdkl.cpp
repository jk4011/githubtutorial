#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

bool visited[MAX][MAX];
int day[MAX][MAX];
bool graph[MAX][MAX];
int w, h;

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; //╩С ©Л го аб  

bool isInside(int y, int x) {
	return (1<=y && 1<=x && y<=h && x<=w);
}

void BFS(int Y, int X) {
	queue<pair<int,int>> q;
	q.push(pair<int,int>(Y,X));
	
	visited[Y][X] = 1;
	day[Y][X] = 1;
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i=0; i<4; i++) {
			int cur_y = y + dir[i][0];
			int cur_x = x + dir[i][1];
			
			if (isInside(cur_y, cur_x) && !visited[cur_y][cur_x] && graph[cur_y][cur_x]) {
				q.push(pair<int, int>(cur_y, cur_x));
				day[cur_y][cur_x] = day[y][x]+1;
				visited[cur_y][cur_x] = true;
			}
		}
	}
}


int main() {
	cin >> h >> w;
	for (int y=1; y<=h; y++) {
		for (int x=1; x<=w; x++) {
			char t;
			cin >> t;
			graph[y][x] = t-'0';
		}
	}
	BFS(1,1);
	
	cout << day[h][w] << endl;
	
	
	
	
	
	
	
}
