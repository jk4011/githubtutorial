#include <iostream>
using namespace std;

struct Eng{
	string before;
	string after;
	string *next;
	
	Eng() {
		next = NULL;
	}
};

int check(char x) {
	if (x == 'U')
		return 1;
			
	if (x == 'N')
		return 2;	
			
	if (x == 'I')
		return 3;	
			
	if (x == 'S')
		return 4;	
			
	if (x == 'T')
		return 5;	
	
	else return 0;	
}

int check2(char x, int y) {
	if (x == 'U' && y == 1)
		return 2;
			
	if (x == 'N' && y == 2)
		return 3;
			
	if (x == 'I' && y == 3)
		return 4;	
			
	if (x == 'S' && y == 4)
		return 5;
	if (x == 'T' && y == 5)
		return 6;
	
	else return 0;	
}

int main() {
	int n;
	cin >> n;
	int num[6] = {0,};
	num[0] = 1;
	
	
	int l[n+1];
	int var = 0;
	string s;
	int first;
	int end, end_;
	for (int i=0; i<n; i++) {
		cin >> s;
		for (int j=0; s.length(); j++) {
			if (check(s[0])) {
				first = check(s[0]);
				end = first;
				while (end) {
					end_ = end;
					end = check2(s[end-1], end);
				}
				end_ -= 1;
				for (int i=first; i<=end_;i++) {
					num[i] += num[first-1];
				}
			}
			else break;
		}
		
		cout << check[5] << endl;
		
	}
}
