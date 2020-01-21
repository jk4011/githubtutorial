#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

vector<int> v;

int main() {
	v = vector<int>(10,12);
	for (auto i: v)
		cout << i << ' ';
}
