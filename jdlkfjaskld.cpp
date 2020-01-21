#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int W, H, ans=99999;
bool graph[100][100];

void DFS(int x, int y, int cnt) {
	if (x>=W || y>=H)
		return;
	else if (x==W-1 && y==H-1) {
		ans = min(ans, cnt);
		return;
	}
	cnt += graph[x][y];
	
	DFS(x+1,y,cnt);
	DFS(x,y+1,cnt);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> W >> H;
	for (int i=0; i<H; i++)
		for (int j=0; j<W; j++) {
			char x;
			cin >> x;
			graph[i][j] = x-'0';
		}
	DFS(0,0,0);
	cout << ans;
}













