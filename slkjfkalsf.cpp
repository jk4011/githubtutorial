#include <iostream>
#include <set>
#include <vector> 
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

const int MAX = 501;
int V, E;
//n2, weight
vector<pair<int,int>> adj[MAX];

vector<int> bellmanFord(int start) {
	vector<int> dist(V+1, INF);
	dist[start] = 0;
	
	bool updated;
	for (int iter=0; iter<V; iter++) {
		updated = false;
		for (int n1=1; n1<=V; n1++) {
//			for (int i=0; i<adj[n1].size(); i++) {
//				int n2 = adj[n1][i].first;
//				int weight = adj[n1][i].second;
//				if (dist[n2] > dist[n1]+weight) {
//					dist[n2] = dist[n1]+weight;
//					updated = true;
//				}
//			}
			for (auto i: adj[n1]) {
				int n2 = i.first;
				int weight = i.second;
				if (dist[n2] > dist[n1]+weight) {
					dist[n2] = dist[n1]+weight;
					updated = true;
				}
			}
		}
		if (!updated)	
			break;
	}
	if (updated)
		dist.clear();
	return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
    for (int i=0; i<E; i++) {
    	int n1, n2, weight;
    	cin >> n1 >> n2 >> weight;
    	adj[n1].push_back({n2, weight});
	}
	vector<int> ans = bellmanFord(1);
	
	if (ans.empty())
		cout << -1 << endl;
	
	else {
		for (int i=2; i<ans.size(); i++) {
			if (ans[i] > 887654321)
				cout << -1 << endl;
			else
				cout << ans[i] << endl;
		}
	}
}



