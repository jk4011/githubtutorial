#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int now, goal, limit, up, down;
int cnt = 0;
bool visited[1000001];
int time[1000001];

bool isOver(int n) {
	return (1>n || limit<n);
}

int BFS() {
	queue<int> q;
	q.push(now);
	visited[now] = true;
	
	while (!q.empty()) {
		int tmp = q.front();
		if (tmp == goal)
			return time[goal];
		q.pop();
		
		if (!isOver(tmp-down) && !visited[tmp-down]) {
			q.push(tmp-down);
			visited[tmp-down]=true;
			time[tmp-down] = time[tmp]+1;
		}
		if (!isOver(tmp+up) && !visited[tmp+up]) {
			q.push(tmp+up);
			visited[tmp+up]=true;
			time[tmp+up] = time[tmp]+1;
		}
	}
	return -1;
}

int main() {
	cin >> limit >> now >> goal >> up >> down;
	int ans = BFS();
	
	if (ans==-1)
		cout << "use the stairs" << endl;
	else 
		cout << ans;
}


//		cout << up <<' ' << down << endl;
//		cout << tmp << time[tmp] << endl;
