#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int *list1 = new int[N];
	int *list2 = new int[M];
	
	int x;
	for (int k=0; k<N; k++) {
		cin >> x;
		list1[k] = x; 
	}
	for (int k=0; k<M; k++) {
		cin >> x;
		list2[k] = x; 
	}
	
	int i=0, j=0;
	
	for (int k=0; k<M+N; k++) {
		if (list1[i] > list2[j]) {
			cout << list2[j] << ' ';
			j++;
		}
		else {
			cout << list1[i] << ' ';
			i++;
		}
		if (i==N && j!=M) {
			for (int k2=0; k2<M-j; k2++) {
				cout << list2[k2+j] << ' ';
			}
			break;
		}
		if (i!=N && j==M) {
			for (int k2=0; k2<N-i; k2++) {
				cout << list1[k2+i] << ' ';
			}
			break;
		}
	}
}
