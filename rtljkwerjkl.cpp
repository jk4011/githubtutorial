#include <bits/stdc++.h>
using namespace std;

vector<int> subset;
int n = 5;


void Cout(int k) {
	for (int i=0; i<k; i++) {
		cout << subset[i] << endl;
	}
}

void search(int k) {
	if (k == n+1) {
		Cout(k);
		cout << endl;
	} 
	else {
		subset.push_back(k);
		search(k+1);
		subset.pop_back();
		search(k+1);
	}
}

int main() {
	search(1);
}

