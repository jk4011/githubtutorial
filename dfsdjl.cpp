#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct DisjointSet {
	vector<int> parent;
	vector<int> rank;
	DisjointSet(int n): parent(n), rank(n, 1) {
		for (int i=0; i<n; i++)
			parent[i] = i;
	}
	int find(int node) {
		if (parent[node] == node)
			return node;
		return parent[node] = find(parent[node]); 
	} 
	
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (v == u)
			return;
		if (rank[u] > rank[v])
			swap(u, v);
		if (rank[u] == rank[v])
			rank[v]++;
		parent[u] = v;
	}
};
int N;
const int MAX = 100;
vector<pair<int,int>> adj[MAX];

int kruskal(vector<pair<int,int>>& ret_graph) {
	vector<pair<int, pair<int,int>>> edges;
	for (int n1=0; n1<N; n1++) {
		for (auto i: adj[n1]) {
			int n2 = i.first;
			int weight = i.second;
			edges.push_back({weight, {n1, n2}});
		}
	}
	sort(edges.begin(), edges.end());
	int totalWeight = 0;
	DisjointSet sets(N);
	for (auto i: edges) {
		int weight = i.first;
		int n1 = i.second.first;
		int n2 = i.second.second;
		if (sets.find(n1) == sets.find(n2))
			continue;
		sets.merge(n1, n2);
		totalWeight += weight;
		ret_graph.push_back({n1, n2});
	}
	
	
	return totalWeight;
}


int main() {
	
}







