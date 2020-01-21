#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

bool graph[1001][1001];
int data[1001][4];
bool visited[1001];
int cnt;
int N;

void DFS(int idx) {
	for (int i=0; i<N; i++) {
		if (graph[idx][i] && !visited[i]) {
			visited[i] = true;
			DFS(i);
		}
	}
}

int main() {
	cin >> N;
	for (int i=0; i<N; i++)
		for (int j=0; j<4; j++)
			cin >> data[i][j];
			
	for (int i=0; i<N; i++) {
		if (data[i][0] > data[i][2])
			swap(data[i][0], data[i][2]);
		if (data[i][1] > data[i][3])
			swap(data[i][1], data[i][3]);
	}
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			graph[i][j] = 1;
	
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (data[j][0] > data[i][2] || data[j][1] > data[i][3] ||
				data[i][0] > data[j][2] || data[i][1] > data[j][3]) {
				graph[i][j] = false;
				graph[j][i] = false;
			}
			else if (data[j][0] > data[i][0] && data[j][1] > data[i][1] &&
					data[j][3] < data[i][3] && data[j][2] < data[i][2]) {
				graph[i][j] = false;
				graph[j][i] = false;
			}
		}
	}
	
	for (int i=0; i<N; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}
	
	for (int j=0; j<N; j++) {
		if (data[j][0]==0 ||data[j][2]==0)
			if (data[j][1]==0 || data[j][3]==0) {
				cnt--;
				cout << 1;
			}
	}
	
	
	cout << cnt;
	
	
}
