#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int direction[4][3][2] = {{{0,0},{0,1},{1,-1}}, {{0,0},{0,1},{1,0}}, {{0,0},{1,0},{0,1}}, {{0,0},{0,1},{-1,0}}};

const int MINF = -987654321;

int W, H;

bool getOut(int i, int j) {
	if (i >= 20 ||i < 0 ||j >= 20 ||j < 0)
		return 1;
	return 0;
}

int Cover(int graph[20][20]) {
	//Ã¹¹øÂ° ºóÄ­ Ã£±â
	int x=-1, y=-1;
	for (int Y=0; Y<H; Y++) {
		bool Break = 0;
		for (int X=0; X<W; X++) {
			if (!graph[Y][X]) {
				x = X;
				y = Y;
				Break = 1;
				break;
			}
		}
		if (Break)
			break;
	}
	cout << y << ' ' << x << endl;
	//¿ì¹° :ÀüºÎ Ã¤¿öÁø °æ¿ì 
	if (x == -1)
		return 1;
	
	int x_, y_;
	// Ã¹¹øÂ° ºóÄ­ ¸ÂÃçº¸±â
	for (int i=0; i<4; i++) {
		x_ = x, y_ = y;
		bool possible = true;
		for (int j=0; j<3; j++) {
			x_ += direction[i][j][0];
			y_ += direction[i][j][1];
//			cout << getOut(x_, y_) << ' ' << graph[x_][y_] << endl;
			if (getOut(x_, y_) || graph[y_][x_])
				possible = false;
		}
		if (!possible)
			continue;
		x_ = x, y_ = y;
		for (int j=0; j<3; j++) {
			x_ += direction[i][j][0];
			y_ += direction[i][j][1];
			graph[y_][x_] = true;
		}
		Cover(graph);
		x_ = x, y_ = y;
		for (int j=0; j<3; j++) {
			x_ += direction[i][j][0];
			y_ += direction[i][j][1];
			graph[x_][y_] = false;
		}
	}
	return 0;
}


int main() {
	int graph[20][20];
	cin >> H >> W;
	cout << W << ' ' << H << endl;
	for (int y=0; y<H; y++)
		for (int x=0; x<W; x++) {
			char a;
			cin >> a;
			if (a=='#')
				graph[y][x] = 1;
			else
				graph[y][x] = 0;
		}
	cout << Cover(graph);
	
}

