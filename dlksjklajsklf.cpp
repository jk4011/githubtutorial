#include <iostream>
#include <set>
#include <vector> 
#include <queue>
#include <algorithm>
using namespace std;

int N;

const int MAX = 100;
	//������ȣ, ���� ����ġ 
vector<pair<int, int>> adj[MAX];

//� ���� ���ߴ����� �ȳ����� '���' ������cost�� ����. 
vector<int> dijstra(int src) {
	//distance 
	vector<int> dist(N, 987654321);
	//���⼭���� ��� 
	dist[src] = 0; 
	//���� �� ���� 
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	//����ġ, ������ȣ 
	pq.push({0,src});
	while (!pq.empty()) {
		int cost = pq.top().first; //������ cost 
		int here = pq.top().second; //������ȣ
		pq.pop();
		
		//cost + adj[here][i].second�� ������ update
		//�ٸ��� �ͼ� update�ߴ��� �� �ߴ��� Ȯ�� 
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











