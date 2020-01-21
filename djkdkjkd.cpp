#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#define MAX 2187
using namespace std;

int graph[MAX][MAX];
int manus;
int zero;
int one;

void incr(int para) {
	if (para==-1)
		manus++;
	if (para==0)
		zero++;
	if (para==1)
		one++;
}
void divSquare(int width, int y, int x);

void square(int width, int y, int x) {
	if (width==1) {
		incr(graph[y][x]);
		return;
	}
	
	for (int i=0; i<width; i++) {
		for (int j=0; j<width; j++) {
			if (graph[y][x] != graph[y+i][x+j]) {
				divSquare(width, y, x);
				return;
			}
		}
	}
	incr(graph[y][x]);
}


int main() {
	int n;
	cin >> n;
	
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			cin >> graph[i][j];
		}
	
	square(n, 0, 0);
	
	cout << manus << endl;
	cout << zero << endl;
	cout << one << endl;
	
	
}

void divSquare(int width, int y, int x) {
	for(int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			square(width/3, y+width/3*i, x+width/3*j);
		}
	}
}













