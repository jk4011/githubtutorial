#include <iostream>
#include <string>
using namespace std;

class Tree {
		char data;
		Tree *left, *right;
	public:
		void setData(char para) {
			data = para;
		}
		void setLeft(Tree *para) {
			left = para;
		}
		void setRight(Tree *para) {
			right = para;
		}
		void static preOrder(Tree *para) {
			if (para) {
				cout << para->data;
				preOrder(para->left);
				preOrder(para->right);
			}
		}
		void static inOrder(Tree *para) {
			if (para) {
				inOrder(para->left);
				cout << para->data;
				inOrder(para->right);
			}
		}
		void static postOrder(Tree *para) {
			if (para) {
				postOrder(para->left);
				postOrder(para->right);
				cout << para->data;
			}
		}
};

int main() {
	int n;
	cin >> n;
	Tree *treeList = new Tree[n];
	for (int i=0; i<n; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		treeList[root-'A'].setData(root);
		if (left != '.')
			treeList[root-'A'].setLeft(&treeList[left-'A']);
		else
			treeList[root-'A'].setLeft(NULL);
		if (right != '.')
			treeList[root-'A'].setRight(&treeList[right-'A']);
		else
			treeList[root-'A'].setRight(NULL);
	}
	Tree::preOrder(treeList);
	cout << endl;
	Tree::inOrder(treeList);
	cout << endl;
	Tree::postOrder(treeList);
	cout << endl;
}























