#include <iostream>
#include <set>
#include <vector> 
#include <queue>
#include <algorithm>
using namespace std;

int N;

const int MAX = 100;
	//정점번호, 간선 가중치 
vector<pair<int, int>> adj[MAX];

//어떤 길을 텍했는지는 안나오고 '모든' 정점의cost를 구함. 
vector<int> dijstra(int src) {
	//distance 
	vector<int> dist(N, 987654321);
	//여기서부터 출발 
	dist[src] = 0; 
	//작은 거 부터 
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	//가중치, 정점번호 
	pq.push({0,src});
	while (!pq.empty()) {
		int cost = pq.top().first; //정점의 cost 
		int here = pq.top().second; //간선번호
		pq.pop();
		
		//cost + adj[here][i].second가 작으면 update
		//다른게 와서 update했는지 안 했는지 확인 
		if (dist[here] < cost)
			continue;
		for (int i= 0; i<adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(nextDist, there));
			}
		}
	}
	
	return dist;
}











