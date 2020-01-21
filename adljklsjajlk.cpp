#include <iostream>
#include <set>
#include <vector> 
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	priority_queue<int> pq;
	pq.push(1); 
	pq.push(3);
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}
	
}
