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

//map<int, int> coords;
//bool isDominated(int x, int y) {
//	map<int, int>::iterator it = coords.lower_bound(x);
//	it--;
//	while (true) {
//		if (it->second > y) break;
//		if (it==coords.begin()) {
//			coords.erase(it);
//		}
//		else {
//			map<int, int>::iterator jt = it;
//			jt--;
//			coords.erase(it);
//			it = jt;
//		}
//	}
//}

int main() {
	map<int, int> coords;
	coords[1] = 3;
	coords[3] = 1;
	map<int, int>::iterator i = coords.lower_bound(2);
	cout << i->first;
	
	return 0;
}
