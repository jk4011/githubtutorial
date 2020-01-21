#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Max(int a, int b) {
	return (a>b? a:b);
}

int main() {
	string S;
	cin >> S;
	int leng = S.length();
	
	vector<int> alpa[26];
	
	string copy_S = "";
	for (int i=leng-1; i>=0; i--) {
		copy_S += S[i];
	}
	S = copy_S;
	cout << S;
//	int plus;
//	int max = 0;
//	int ind;
//	for (int i=0; i<leng; i++) {
//		ind = S[i] - 'a';
//		
//		for (vector<int>::iterator j=alpa[ind].begin(); j<alpa[ind].end(); j++) {
//			plus = 1;
//			if (S[i+max] == S[*j+max]) {
//				while (S[i+plus] == S[*j+plus])
//					plus++;
//				max = Max(plus, max);
//			}
//		}
//		alpa[ind].insert(alpa[ind].end(),i);
//	}
//	cout << max << endl;
	
}
