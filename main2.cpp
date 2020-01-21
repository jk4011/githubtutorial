#include <iostream>
#include <vector>
#include <fstream>
#include "a.h"
using namespace std;

int main() {
	ifstream in("input.txt");
	vector<int> arr;
	a(arr, in);
	return 0;
}
