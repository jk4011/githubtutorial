#include <iostream>
#include <set>
#include <vector> 
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n): parent(n), rank(n, 1) {
		for (int i=0; i<n; i++)
			parent[i] = i;
	}
	int find(int node) {
		if (node == parent[node])
			return node;
		return parent[node] = find(parent[node]);
	}
	void merge(int n1, int n2) {
		n1 = find(n1);
		n2 = find(n2);
		if (n1 == n2)
			return;
		if (rank[n1] > rank[n2])
			swap(n1, n2);
		if (rank[n1] == rank[n2])
			rank[n2]++;
		parent[n1] = n2;
	}
};

const int MAX = 10001;
int V, E;
//node, weight
vector<pair<int,int>> adj[MAX];

int kruskal(vector<pair<int,int>>& selected) {
	int ret = 0;
	vector<pair<int, pair<int,int>>> edges;
	for (int n1=0; n1<V; n1++) {
		for (auto i:adj[n1]) {
			int n2 = i.first;
			int weight = i.second;
			edges.push_back({weight,{n1, n2}});
		}
	}
	sort(edges.begin(), edges.end());
	DisjointSet sets(V);
	for (auto i: edges) {
		int weight = i.first;
		int n1 = i.second.first;
		int n2 = i.second.second;
		if (sets.find(n1) == sets.find(n2))
			continue;
		sets.merge(n1, n2);
		selected.push_back({n1, n2});
		ret += weight;
	}
	return ret;
}

int main() {
	cin >> V >> E;
	for (int j=0; j<E; j++) {
		int n1, n2, weight;
		cin >> n1 >> n2 >> weight;
		adj[n1-1].push_back({n2-1, weight});
		adj[n2-1].push_back({n1-1, weight});
	}
	
	vector<pair<int,int>> ans;
	kruskal(ans);
//	for (auto i: ans) {
//		cout << i.first << ' ' << i.second << endl;
//	}
	
	cout << kruskal(ans) << endl;
	
}




