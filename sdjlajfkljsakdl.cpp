#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int N, M, V;

vector<int> *graph;
bool visit[20001][2];


void bfs(int V) {
	visit[V][0] = 1;
//	cout << V << ' ';
	bool color = 0;
	visit[V][1] = color;
	
	queue<int> q;
	q.push(V);
	while (!q.empty()) {
		int tmp = q.front();
		color = !visit[tmp][1];
		q.pop();
		int size = graph[tmp].size();
		for (int i=0; i<size; i++) {
			if (visit[graph[tmp][i]][0]==0) {
				q.push(graph[tmp][i]);
				visit[graph[tmp][i]][0] = 1;
				visit[graph[tmp][i]][1] = color;
			}
			else if (visit[graph[tmp][i]][1]!=color) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "Yes" << endl;
	return;
}

int main() {
	int n;
	cin >> n;
	graph = new vector<int>[20001];
	for (int i=0; i<n; i++) {
		for (int j=0; j<20001; j++) {
			visit[j][0] = 0;
			visit[j][1] = 0;
		}
		cin >> N >>M;
	
		for (int i=0; i<M; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		bfs(1);
		delete[] graph;
		graph = new vector<int>[20001];
	}
	
}
