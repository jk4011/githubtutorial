#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<float,float>> area1, hi1, lo1, area2, hi2, lo2;
int N;

void setArea(vector<pair<float,float>> &area) {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		float x, y;
		cin >> x >> y;
		area.push_back({y, x});
	}
}

int main() {
	cin >> N;
	for (int i=0; i<N; i++) {
		setArea(area1);
		setArea(area2);
	}
		
	
	
	
	
	
	
	
}
