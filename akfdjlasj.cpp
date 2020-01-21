#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100;

//node, weight
vector<pair<int,int>> adj[MAX];

vector<int> dijkstra(int src) {
	vector<int> ret(MAX, 987654321);
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0, src});
	
	while (!pq.empty()) {
		int n1 = pq.top().second;
		int cost = pq.top().first;
		
		for (auto i: adj[n1]) {
			int n2 = i.first;
			int weight = i.second;
			
			if (ret[n2] > cost + weight)
				ret[n2] = cost + weight;
				pq.push({ret[n2], n2});
		}
		
		
	}
	
	
	
	return ret;
}


int main() {
	
	
	
}



