#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX = 10001;

int V, E;
vector<pair<int, pair<int,int>>> edges;

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n): parent(n+1), rank(n+1, 1) {
		for (int i=1; i<=n; i++)
			parent[i] = i;
	}
	int find(int node) {
		if (parent[node] == node)
			return node;
		return parent[node] = find(parent[node]);
	}
	void merge(int n1, int n2) {
		n1 = find(n1);
		n2 = find(n2);
		if (find(n1) == find(n2))
			return;
		if (rank[n1] > rank[n2])
			swap(n1, n2);
		if (rank[n1] == rank[n2])
			rank[n2]++;
		parent[n1] = n2;
	}
};

int kruskal() {
	int ret;
	sort(edges.begin(), edges.end());
	DisjointSet sets(V);
	for (auto i: edges) {
		int weight = i.first;
		int n1 = i.second.first;
		int n2 = i.second.second;
		if (sets.find(n1) == sets.find(n2))
			continue;
		ret += weight;
		sets.merge(n1, n2);
	}
	return ret;
}

int main() {
	cin >> V >> E;
	for (int i=0; i<E; i++) {
		int n1, n2, weight;
		cin >> n1 >> n2 >> weight;
		edges.push_back({weight, {n1, n2}});
	}
	cout << kruskal();
}








