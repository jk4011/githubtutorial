#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	int month[13] = {0, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
					
	string week[] = {"MON","TUE","TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	
	int x, y;
	cin >> x >> y;
	
	for (int i=1; i<y; i++) {
		x += month[i];
	}
	
	cout << x;
	
	
//	input: x, y
//	output: SUN
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
}
