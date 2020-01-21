#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
	for (int i=0; i<3; i++) {
		queue<int> q;
		if (i=0)
			q.push(3);
		cout << q.front() << endl; 
		q.push(5);
	}
}
