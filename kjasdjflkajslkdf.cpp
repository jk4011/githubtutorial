#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int N, M, V;

int graph[1001][1001];
int visit[1001];

void dfs(int V) {
	visit[V] = 1;
	cout << V << ' ';
	for (int i=1; i<=1000; i++) {
		if (graph[V][i]==1 && visit[i]==0) {
			dfs(i);
		}
	}
}

void bfs(int V) {
	visit[V] = 1;
//	cout << V << ' ';
	queue<int> q;
	q.push(V);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i=1; i<=1000; i++) {
			if (graph[tmp][i]==1 && visit[i]==0) {
//				cout << i << ' ';
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}

bool all_visit() {
	for (int i=1; i<=1000; i++) {
		if (visit[i]==0)
			return 0;
	}
	return 1;
}

int main() {
	cin >> N >> M;
	
	int a, b;
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	
	int num = 0;
	for (int i=1; i<=N; i++) {
		if (visit[i]==0) {
			bfs(i);
			num++;
		}
	}
	cout << num << endl;
}







