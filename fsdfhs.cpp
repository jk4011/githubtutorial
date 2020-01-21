#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	int x;
	for (int i=0; i<h; i++)
		for (int j=0; j<w; j++)
			cin >> x;
	for (int i=0; i<h; i++) {
		for (int j=0; j<w-1; j++) {
			
			if (i%2==1)
				cout << 'L';
			else
				cout << 'R';
		}
		if (i != h-1)
			cout << 'D';
	}
	
}







