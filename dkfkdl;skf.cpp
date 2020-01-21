#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct node {
	vector<node*> children;
};

int longest;

int height(node* root) {
	vector<int> h;
	for (int i=0; i < root->children.size(); i++) {
		h.push_back(height(root->children[i]));
	}
	if (h.empty());
}

int main() {
	
}









