#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std; 

struct RMQ {
	int n;
	vector<int> rangeMin; 
	RMQ(const vector<int>& array) {
		n = array.size();
		rangeMin.resize(4*n);
		init(array, 0, n-1, 1);
	}
	int init(const vector<int>& array, int left, int right, int node) {
		if (left == right)
			return rangeMin[node] = vector[left];
		if (left == right) // mid를 쓸 기전 left right 같으면 미리 빠지기 
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node*2);
		int rightMin = init(array, mid+1, right, node*2+1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
	//node는 항상 nodeLeft, nodeRight와 대응된다. 
	int query(int i, int j, int node, int nodeLeft, int nodeRight) { //공동 구간에서 최소값을 return 
		
		if (i > nodeRight || j < nodeLeft)
			return 987654321;
		else if (i <= nodeLeft && j >= nodeRight) //i-j 가 더 넓으면 
			return rangeMine[node];
		else {                                           //겹치거나 node가 더 넓으면 nodeRight-nodeLeft를 나눠줌 
			int mid = (nodeLeft + nodeRight) / 2;
			return min(query(i, j, node*2, nodeLeft, mid),
					   query(i, j, node*2+1, mid+1, nodeRight));
		}
	}
	int query(int left, int right) { // left~right에서 가장 작은 값 return 
		return query(left, right, 1, 0, n-1);
	}
	int update(int idx, int newValue, int node, int nodeLeft, int nodeRight) {
		if (nodeLeft > index || nodeRight < index)
			return rangeMin[node];
		if (nodeLeft == nodeRight)
			return rangeMin[node] = newValue;
		
		int mid = (nodeLeft + nodeRight) / 2;
		rangeMin[node] = min(update(idx, newValue, node, nodeLeft, mid),
							update(idx, newValue, node, mid+1, nodeRight));
		return rangeMin[node];
	}
};





