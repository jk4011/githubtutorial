#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int n,N;
string graph[15];

bool isMoum(string x) {
	for (int i=0; i<n; i++) {
		if (x[i]=='a'||x[i]=='e'||x[i]=='i'||x[i]=='o'||x[i]=='u'||x[i]=='y')
			return 1;
	}
	return 0;
}
bool isZaum(string x) {
	int sum=0;
	for (int i=0; i<n; i++) {
		if (x[i]!='a'&&x[i]!='e'&&x[i]!='i'&&x[i]!='o'&&x[i]!='u'&&x[i]!='y')
			sum++;
	}
	if (sum>=2)
		return 1;
	else
		return 0; 
}

void DFS(int idx, int now, string sum) {
//	cout << sum << endl;
	if (now == n) {
		if (isMoum(sum) && isZaum(sum))
			cout << sum << endl;
		return;
	}
	for (int i=idx+1; i<N; i++) {
		DFS(i, now+1, sum+graph[i]);
	}
}

int main() {
	cin >> n >> N;
	for (int i=0; i<N; i++)
		cin >> graph[i];
	sort(graph, graph+N);
	
	DFS(-1,0,"");
}
