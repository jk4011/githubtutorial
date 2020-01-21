#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std; 

int n, numPlus, numOutput;
vector<int> arr;
vector<int> rangeMin; //segment tree

int init(int left, int right, int node) { //rangeMin initialize, return minimun of range
	if (left == right)
		return rangeMin[node] = arr[left];
	int mid = (left + right)/2;
	int minLeft = init(left, mid, node*2);
	int minRight = init(mid+1, right, node*2+1);
	return rangeMin[node] = min(minLeft, minRight);
}



int query(int i, int j, int node, int nodeLeft, int nodeRight) { //using rangeMin, get minimum between i~j
	if (j < nodeLeft || nodeRight < i)
		return 987654321;
	if (i <= nodeLeft && nodeRight <= j)
		return rangeMin[node];
	
	int mid = (nodeRight + nodeLeft) / 2;
	int minLeft = query(i, j, node*2, nodeLeft, mid);
	int minRight = query(i, j, node*2+1, mid+1, nodeRight);
	return min(minLeft, minRight);
}

int main() {
	n = 5;
	rangeMin.resize(20);
	arr = {1,3,9,7,4};
	init(0,4,1);
	
//	cin >> n >> numPlus >> numOutput;
//	arr.resize(n);
//	rangeMin.resize(4*n);
//	
//	for (int i=0; i<n; i++) {
//		int x;
//		cin >> x;
//		arr.push_back(x);
//	}
//	for (int i=0; i<umPlus+numOutput; i++) {
//		int a, b, c, d;
//		cin >> a;
//		if (a==1) {
//			cin >> b >> c >> d;
//		}
//		else if (a==2) {
//			cin >> b >> c;
//			
//		}
//	}
	
}



