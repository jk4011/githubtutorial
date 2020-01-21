#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> *graph;
bool visit[1001];

void bfs(int v) {
	visit[v] = 1;
	int size = graph[v].size();
	
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		int tmp = q.front();
//		cout <<tmp << endl;
		q.pop();
		
		int size = graph[tmp].size();
		for (int i=0; i<size; i++) {
			if (visit[graph[tmp][i]] == 0) {
				q.push(graph[tmp][i]);
				visit[graph[tmp][i]] = 1;
			}
		}
	}
}

int main() {
	graph = new vector<int>[1001];
	int n;
	cin >> n;
	
	for (int i=0; i<n; i++) {
		int N;
		cin >> N;
		for (int j=1; j<=N; j++) {
			int x;
			cin >> x;
			graph[x].push_back(j);
			graph[j].push_back(x);
		}
		
		int num = 0;
		for (int j=1; j<=N; j++) {
			if (visit[j] == 0) {
				bfs(j);
				num++;
			}
		}
		for (int i=0; i<1001; i++) {
			visit[i] = 0;
		}
		delete[] graph;
		graph = new vector<int>[1001];
		cout << num << endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
}
