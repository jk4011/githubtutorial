#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

int parent[MAX];
vector<int> map[MAX];
int n;

void DFS(int V) {
	queue<int> q;
	q.push(V);
	
	while(!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (vector<int>::iterator j=map[tmp].begin(); j<map[tmp].end(); j++) {
				if (!parent[*j]) {
					q.push(*j);
					parent[*j] = tmp;
				}
		}
	}
}

int main() {
	parent[1] = 1;
	cin >> n;
	for (int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	
	DFS(1); 
	
	for (int i=2; i<=n; i++) {
		cout << parent[i] << '\n';
	}
}
