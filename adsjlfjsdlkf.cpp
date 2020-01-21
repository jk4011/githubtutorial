#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

int inDeg[501];
int data[501];
set<int> graph[501];
int n, N, M;

bool isImpo;

void BFS() {
	
	if (isImpo) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	bool IsQues = 0;
	queue<int> q;
	vector<int> ret;
	for (int i=1; i<=N; i++) {
		if (inDeg[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		if (q.size() > 1) IsQues = true;
		int tmp = q.front();
		q.pop();
		ret.push_back(tmp);
		
		for (auto i: graph[tmp]) {
			inDeg[i]--;
			if (inDeg[i]==0)
				q.push(i);
		}
	}
	if (ret.size() != N || IsQues) {
		cout << "?" << endl;
		return;
	}
	for (int i=0; i<N; i++)
		cout << ret[i] << ' ';
	cout << endl;
	return;
}

int main() {
	cin >> n;
	for (int x=0; x<n; x++) {
		
	cin >> N;
		
		memset(data,0,sizeof(data));
		memset(inDeg,0,sizeof(inDeg));
		isImpo=0;
		for (int i=0; i<=N; i++)
			graph[i].clear();
	
	for (int i=1; i<=N; i++)
		cin >> data[i];
	for (int i=1; i<=N; i++)
		for (int j=N; j>i; j--)
			graph[data[i]].insert(data[j]);
	
	int N2;
	cin >> N2;
	for (int i=0; i<N2; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].insert(b);
		if (!graph[b].erase(a))
			isImpo = true;
	}
	
	for (int i=1; i<=N; i++)
		for (auto j: graph[data[i]])
			inDeg[j]++;
	BFS();
	}
}
