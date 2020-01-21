#include <iostream>
#include <set>
#include <vector> 
#include <queue>
#include <algorithm>
using namespace std;





struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n): parent(n), rank(n, 1) {
		for(int i=0; i<n; i++) {
			//at first, parent is itself
			parent[i] = i;
		}
	}
	int find(int u) {
		if (u == parent[u])
			return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u==v)
			return;
		if (rank[u] > rank[v])
			swap(u, v);
		//v의 랭크가 크면 원래 크니 높일 필요x 
		if (rank[u] == rank[v])
			rank[v]++;
		parent[u] = v;
	}
};

const int MAX = 100;
int V;
vector<pair<int, int>> adj[MAX];


int kruskal(vector<pair<int, int>>& selected) {
	int ret = 0;
	vector<pair<int, pair<int, int>>> edges;
	for (int n1=0; n1<V; n1++) {
		for (int i=0; i < adj[i].size(); i++) {
			int n2 = adj[n1][i].first;
			int weight = adj[n1][i].second;
			edges.push_back({weight, {n1, n2}});
		}
	}
	sort(edges.begin(), edges.end());
	Disjointset sets(V);
	for (int i=0; i<edges.size(); i++) {
		int cost = edges[i].first;
		int n1 = edges[i].second.first;
		int n2 = edges[i].second.second;
		
		if (sets.find(n1) == sets.find(n2))
			continue;
		sets.merge(n1, n2);
		selected.push_back({u,v});
		ret += cost;
	}
	return ret;
}




int main() {
	
}















