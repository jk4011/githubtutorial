#include <iostream>
#include <algorithm>
#define MAX 200001
#define ll long long

using namespace std;

ll house[MAX];
long long distance[MAX-1];
ll numSpot;

int main() {
	int n;
	cin >> n;
	cin >> numSpot;
	
	cin >> house[0];
	for (int i=1; i<n; i++) {
		cin >> house[i];
		distance[i-1] = house[i] - house[i-1];
	}
	
	for (int i=1; i<n; i++)
		cout << distance[i-1];
	
	
	
	
	
}
