#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;

map<int, int> m;
map<int, bool> visited;
int start = 123456789;
int start2 = 192345678;
int inp = 0;
vector<int> v;

int change(int para, int i, int j) {
	i = 9-i;
	j = 9-j;
	int x = para / (int)pow(10,i) % 10;
	int y = para / (int)pow(10,j) % 10;
	return para - (x-y)*pow(10, i) - (y-x)*pow(10, j);
}

int pushV(int para) {
	v.clear();
	int pos0;
	for (int i=0; i<=8; i++) {
		if (para/(int)pow(10,i) % 10 == 9)
			pos0 = 9-i;
	}
//	cout << pos0 << endl;
	if (pos0 % 3 != 1)
		v.push_back(change(para, pos0, pos0-1));
	if (pos0 % 3 != 0)
		v.push_back(change(para, pos0, pos0+1));
	if (pos0 >= 4)
		v.push_back(change(para, pos0, pos0-3));
	if (pos0 <= 6)
		v.push_back(change(para, pos0, pos0+3));
}


void BFS() {
	queue<int> q;
	visited[start] = true;
	q.push(start);
	
	while(!q.empty()) {
		int tmp = q.front();
		if (tmp == inp)
			return;
		q.pop();
		pushV(tmp);
		for (int i=0; i<v.size(); i++) {
			if (!visited[v[i]]) {
				q.push(v[i]);
				visited[v[i]] = true;
				m[v[i]] = m[tmp]+1;
			}
		}
	}
}

int main() {
	for (int i=0; i<9; i++) {
		int x;
		cin >> x;
		inp *= 10;
		if (x==0)
			inp += 9;
		else
			inp += x;
	}
	BFS();
	if (inp==start)
		cout << 0;
	else if (m[inp]==0)
		cout << -1;
	else
		cout << m[inp];
}
