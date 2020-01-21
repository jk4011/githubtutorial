#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int K;
int list[13];
int data[13];

void dfs(int now, int depth) {
	data[depth] = list[now];
	
	if (depth==5) {
		for (int i=0; i<6; i++)
			cout << data[i] << ' ';
		cout << endl;
		return;
	}
	
	for (int i = now+1; i<K; i++) {
		dfs(i, depth+1);
	}
} 

int main() {
	
	while (cin >> K && K!=0) {
		for (int i=0; i<K; i++)
			cin >> list[i];
		
		for (int i=0; i<K; i++)
			dfs(i,0);
		cout << endl;
	}
}
