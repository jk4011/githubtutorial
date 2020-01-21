#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

pair<int,int> heros[20001];
int msters[20000];


int main() {
	int N;
	cin >> N;
	for (int i=0; i<N; i++) {
			int numM, numH;
			cin >> numM;
			for (int k=0; k<numM; k++)
				cin >> msters[k];
			cin >> numH;
			for (int k=0; k<numH; k++) {
				int x, y;
				cin >> x >> y;
				heros[k] = {y, x};
			}
			sort(heros, heros+numH);
			cout << msters[2] << endl;
			cout << heros[2].first << heros[2].second << endl;
	}
	
}
