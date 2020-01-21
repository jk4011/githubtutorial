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
vector<int> sum; //segment tree

int init(int left, int right, int node) { //return sum
	if (left == right)
		return sum[node] = arr[left];
//	cout << left << ' ' << right << endl;
	int mid = (left + right)/2;
	int sumLeft = init(left, mid, node*2);
	int sumRight = init(mid+1, right, node*2+1); //init 2개 재귀가 lgn이구나.... 
	return sum[node] = sumLeft+sumRight;
}

int update(int idx, int node, int nodeLeft, int nodeRight) { //return sum
	if (idx < nodeLeft || nodeRight < idx)	
		return sum[node];
	if (nodeLeft == nodeRight)
		return sum[node] = arr[idx];
	int mid = (nodeLeft+nodeRight)/2;
	int leftSum = update(idx, node*2, nodeLeft, mid);
	int rightSum = update(idx, node*2+1, mid+1, nodeRight);
	return sum[node] = leftSum + rightSum;
}
int update(int i, int j, int plus) {
	for (int x=i-1; x<=j-1; x++) {
		arr[x] += plus;
	}
	for (int x=i-1; x<=j-1; x++) {
		update(x, 1, 0, n-1);
	}
}

int query(int i, int j, int node, int nodeLeft, int nodeRight) {
	if (nodeRight < i || j < nodeLeft)
		return 0;
	if (i <= nodeLeft && nodeRight <= j)
		return sum[node];
	int mid = (nodeLeft + nodeRight)/2;
	int sumLeft = query(i,j,node*2, nodeLeft, mid);
	int sumRight = query(i,j,node*2+1, mid+1, nodeRight);
	return sumLeft+sumRight;
}
int query(int i, int j) {
	return query(i-1, j-1, 1 , 0, n-1);
}

int main() {
	cin >> n >> numPlus >> numOutput;
	sum.resize(4*n);
	
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	init(0,n-1,1);
	for (auto i: sum)
		cout << i << ' ';
	cout << endl;
	for (int i=0; i<numPlus+numOutput; i++) {
		int a, b, c, d;
		cin >> a;
		if (a==1) {
			cin >> b >> c >> d;
			update(b,c,d);
		}
		else if (a==2) {
			cin >> b >> c;
			cout << query(b,c) << endl;
		}
	}
}


