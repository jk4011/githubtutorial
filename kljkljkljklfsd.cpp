#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

int visited[MAX][MAX];
int graph[MAX][MAX];
int cnt;
int day[MAX][MAX];
int w, h;

int Min(int a, int b) {
	return a>b? b:a; 
}
int Max(int a, int b) {
	return a<b? b:a; 
}

void DFS(int x, int y, int d) {
	visited[x][y] = true;
	graph[x][y] = true;
	day[x][y] = Min(day[x][y], d);
	if (x==6 && y==4)
		cout << endl;
	cout << x << ' '<<y<<' '<<day[x][y]<<endl;
//	cout << x << ' ' << y << endl;
	if (x+1 <= w && graph[x+1][y]!=-1 && !visited[x+1][y]) {
		DFS(x+1, y, d+1);
	}
	if (x-1 > 0 && graph[x-1][y]!=-1 && !visited[x-1][y]) {
		DFS( x-1,y,d+1);
	}
	if (y+1 <= h && graph[x][y+1]!=-1 && !visited[x][y+1]) {
		DFS(x, y+1, d+1);
	}
	if (y-1 > 0 && graph[x][y-1]!=-1 && !visited[x][y-1]) {
		DFS(x, y-1, d+1);
	}
}


int main() {
	
	cin >> w >> h;
	
	for (int i=0; i<MAX; i++) {
		for (int j=0; j<MAX; j++)
			day[i][j] = 9999;
	} 
	
	for (int y=1; y<=h; y++)
		for (int x=1; x<=w; x++) {
			cin >> graph[x][y];
			if (graph[x][y]==1)
				day[x][y]=0;
		}
		
	for (int y=1; y<=h; y++) {
		for (int x=1; x<=w; x++) {
			if (day[x][y]==0) {
				memset(visited, 0, sizeof(visited));
				DFS(x, y, 0);
			}
					
		}
	}
//	int max = 0;
//	
//	for (int x=1; x<=w; x++) {
//		for (int y=1; y<=h; y++) {
//			if (day[x][y]!=9999)
//				max = Max(max, day[x][y]);
//		}
//	}
//	
//	cout << max << endl;
	return 0;
}
