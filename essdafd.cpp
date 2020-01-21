#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

stack<char> st;
map<char, char> m;

int main() {
	m[']'] = '[';
	m['}'] = '{';
	m[')'] = '(';
	
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		
	string line;
	cin >> line;
	bool isYes = true;
	for (int i=0; i<line.length(); i++) {
		char x = line[i];
		if (x==']' ||x==')' ||x=='}') {
			if (st.empty() || m[x] != st.top()) {
				isYes = false;
				break;
			}
			else 
				st.pop();
		}
		else
			st.push(x);	
	}
	if (isYes)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
		
		
	}
	
}
