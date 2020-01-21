#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;

int N, M;
int ans[MAX];
vector<pair<int,int>> graph[MAX];
bool middle[MAX];

void BFS() {
	queue<int> q;
	q.push(N);
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (middle[cur]) {
			for (auto i: graph[cur]) {
				int next = i.first;
				int num = i.second*ans[cur];
				q.push(next);
				ans[next] += num;
			}
			ans[cur] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b,c});
		middle[a] = true;
	}
	ans[N] = 1;
	BFS();
	for (int i=1; i<N; i++) {
		if (ans[i])
			cout << i << ' ' << ans[i] << endl;
	}
}


