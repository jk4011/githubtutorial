#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 100001
using namespace std;

int n;
vector<pair<int,int>> graph[MAX];
bool isLeaf[MAX];
bool visited[MAX];
int maxRoot;


int Max(int a, int b) {
	return a>b? a:b;
}

int DFS(int V) {
	visited[V] = true;
	int max=0;
	for (int i=0; i<graph[V].size(); i++) {
		if (!visited[graph[V][i].first]) {
			int next = graph[V][i].first;
			int leng = graph[V][i].second;
			int tmp = DFS(next);
			if (max < leng + tmp) {
				max = leng + tmp;
				if (V!=1 && graph[V].size()==1)
					maxRoot = V;
			}
			
		}
	}
	return max;
}

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		int n1, n2, leng;
		cin >> n1;
		
		while (1) {
			cin >> n2;
			if (n2==-1) break;
			cin >> leng;
			
			graph[n1].push_back(pair<int,int>(n2, leng));
		}
	}
	DFS(4);
	cout << maxRoot << endl;
	memset(visited, 0, sizeof(visited));
	cout << DFS(maxRoot) << '\n'; 
}

