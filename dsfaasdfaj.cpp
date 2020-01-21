#include <iostream>
#include <set>
#include <vector> 
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 20001;
int V, E;

//node, weight 
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start) {
	vector<int> dist(V+1, INF);
	dist[start] = 0;
	//cost, node
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0, start});
	
	while(!pq.empty()) {
		int costU = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		
		if (dist[u] < costU)
			continue;
		
		for (auto i: graph[u]) {
			int v = i.first;
			int weight = i.second;
			if (dist[v] > costU + weight) {
				dist[v] = costU + weight;
				pq.push({dist[v], v});
			}
		}
	}
	
	return dist;
}



int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
	int start;
	cin >> V >> E >> start;
	for (int i=0; i<E; i++) {
		int v, u, weight;
		cin >> v >> u >> weight;
		graph[v].push_back({u, weight});
//		graph[u].push_back({v, weight});
	}
	
	vector<int> ans = dijkstra(start);
	
	for (int i=1; i<ans.size(); i++) {
		if (ans[i] == INF)
			cout << "INF" << endl;
		else
			cout << ans[i] << endl;
	}
}










