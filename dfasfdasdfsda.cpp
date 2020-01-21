#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 10000000;
int hi, lo, want;
int numdiv[MAX], mindiv[MAX];




void erasto() {
	for (int i=2; i<=sqrt(MAX); i++) {
		mindiv[i] = i;
	}
	for (int i=2; i<=sqrt(MAX); i++) {
		if (mindiv[i] == i)
			for (int j=2; i*j<=MAX; j++) {
				if (mindiv[i*j] == i*j) {
					mindiv[i*j] = i;
				}
				
			}
	}
}

void getNum() {
	for (int i=2; i<=sqrt(MAX); i++) {
		int num=0;
		int x = i;
		while (x != 1) {
			x /= mindiv[x];
			num++;
		}
		numdiv[i] = num;
	}
}



int main() {
	erasto();
	getNum();
	for (int i=486; i<1000; i++) {
		cout << i << ' ' << mindiv[i] << endl;
	}
	int N;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> want >> lo >> hi;
		int cnt = 0;
		for (int j=lo; j<=hi; j++) {
//			cout << numdiv[j] << ' ' << want << endl;
			if (numdiv[j]==want)
				cnt++;
		}
		cout << cnt << endl;
	}
	
	
	
	
	
	
	
}







