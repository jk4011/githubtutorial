#include <iostream>
#include <set>
#include <vector> 
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	vector<int> a = {4,3,2,1};
	reverse(a.begin(), a.begin()+2);
	for (auto i: a)
		cout << i << ' ';
}
