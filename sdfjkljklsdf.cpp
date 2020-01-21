#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Search {
	private:
		vector<vector<int>> list;
		stack<int> stk_dfs;
		queue<int> stk_bfs;
		bool visited[1000];
	public:
		Search(int n) {
			list.resize(n+1);
			for (int i=0; i<1000; i++)
				visited[i] = 0;
		}
		void insert(int a, int b) {
			list[a].push_back(b);
			list[b].push_back(a);
		}
		void search(int start) {
			int x = list[start][0];
			if (visited[x] == 0) {
				cout << x;
				visited[x] = 1;
			}
			list.erase(list.begin());
		}
		
};


int main() {

	
	return 0;
}
