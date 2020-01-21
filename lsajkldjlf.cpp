#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;

vector<int> circuit;
int graph[MAX][MAX];
int n;

bool notEulerCircuit() {
	for (int i=0; i<n; i++) {
		int sum = 0;
		for (int j=0; j<n; j++) {
			sum += graph[i][j];
		}
		if (sum % 2 == 1)
			return false;
	}
	return true;
}

void getEulerCircuit(int here) {
	for (int there=0; there<n; there++) {
		while (graph[here][there] > 0) {
			graph[here][there]--;
			graph[there][here]--;
			getEulerCircuit(there);
		}
	}
	circuit.push_back(here);
} 

int main() {
	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> graph[i][j];
	getEulerCircuit(0);
	for (auto i: circuit)
		cout << i + 1 << ' ';
	
}
