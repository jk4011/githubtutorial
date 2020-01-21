#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MAX = 10000;

bool visited[26];
set<int> graph[26];
string data[MAX];
vector<char> ret;
bool isWrong;


void dfs(int here) {
	visited[here] = true;
	ret.push_back(here);
	for (auto i: graph[here]) {
		if (!visited[i])
			dfs(i);
		else {
			isWrong = true;
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> data[i];
	}
	for (int i=0; i<N-1; i++) {
		int leng = min(data[i].length(), data[i+1].length());
		for (int j=0; j<leng; j++) {
			if (data[i][j] != data[i+1][j]) {
				graph[data[i][j]-'a'].insert(data[i+1][j]-'a');
				break;
			}
		}
	}
	for (int i=0; i<26; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	if (isWrong) {
		cout << "INVALID HYPOTHESIS" << endl;
	}
	else {
	for (int i=25; i>=0; i--) { 
		cout << (char)(ret[i]+'a');
	}
	cout << endl;
	}
		

}
