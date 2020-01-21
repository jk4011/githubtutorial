#include <iostream>
#include <string>

using namespace std;

int Min(int *list, int n) {
	
	int m = list[0];
	for (int i=1; i<n; i++) {
		if (m > list[i]) m = list[i];
	}
	return m;
}

int IntMin2(int a, int b) {
	if (a < b) return a;
	else return b;
}

int IntMin3(int a, int b, int c) {
	return IntMin2(a, IntMin2(b, c));
}

int DP(int n, int *list) {
	if (list[n] != 0) return list[n]; //불러오기
	if (n==2) return 1;
	if (n==3) return 1;
	
	int ans;
	
	int div2=0, div3=0;
	div2 = n%2;
	div3 = n%3;
	
	if (!div2 && !div3) {
		ans = IntMin3(DP(n/2, list), DP(n/3, list), DP(n-1, list)) + 1;
		list[n] = ans;
		return ans;
	}
	if (!div2 && div3) {
		ans = IntMin2(DP(n/2, list), DP(n-1, list)) + 1;
		list[n] = ans;
		return ans;
	}
	if (div2 && !div3) {
		ans = IntMin2(DP(n/3, list), DP(n-1, list)) + 1;
		list[n] = ans;
		return ans;
	}
	if (div2 && div3) {
		ans = DP(n-1, list) + 1;
		list[n] = ans;
		return ans;
	}
		
	return 0;
}

int main() {
	int x;
	int list[1000000] = {0, };
	cin >> x;
	cout << DP(x, list);
	
	return 0;
}


















