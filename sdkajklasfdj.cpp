#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100;
const int MAX_LENGTH = 80;

pair<int,int> dir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int N, M, K;
int result; //
string target;
string board[MAX];
int cache[MAX][MAX][MAX_LENGTH]; //

int func(int y, int x, int idx) {
	int &result = cache[y][x][idx];
	
	if (result != -1) { //
		return result;
	}
	
	if (idx == target.length()) { //
		return 1;
	}
	
	result = 0; //
	
	for (int k=0; k<4; k++) {
		int y_ = y;
		int x_ = x;
		
		for (int i=0; i<K; i++) {
			int nextY = y_ + dir[k].first;
			int nextX = x_ + dir[k].second;
			
			if (nextY < 0 || nextY >= N || nextX < 0 || nextX > M)
				break;
			
			if (board[nextY][nextX] == target[idx]) {
				result += func(nextY, nextX, idx + 1);
			}
			y_ = nextY;
			x_ = nextX;
		}
	}
	
	return result;
}

int main() {
	cin >> N >> M >> K;
	for (int i=0; i<N; i++)
		cin >> board[i];
	cin >> target;
	
	vector<pair<int,int>> start;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (board[i][j] == target[0])
				start.push_back({i,j});
		}
	}
	
	memset(cache, -1, sizeof(cache));
	
	for (int i=0; i < start.size(); i++) {
		int y = start[i].first;
		int x = start[i].second;
		
		result += func(y,x,1); // func = dfs + dp
	}
	cout << result << endl;
}




















