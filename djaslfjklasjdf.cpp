#include <iostream>
#include <string>
using namespace std;


int main() {
	int n;
	cin >> n;
	
	string x;
	int leng;
	
	for (int i=0; i<n; i++) {
		cin >> x;
		leng= x.length();
		if (leng == 7 && x[0] != x[2]) {
			if ((x[0]==x[1] && x[0]==x[4])) {
				if (x[2]==x[3] && x[2]==x[5] && x[2]==x[6])
					cout << 1 << endl;
				else
					cout << 0 << endl;
				}
			else
				cout << 0 << endl;
		}
		else
			cout << 0 << endl;
	
		
	}
}

