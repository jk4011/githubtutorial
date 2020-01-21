#include <bits/stdc++.h>
#include<stdio.h>
#include<vector>
using namespace std;
int isVisited[9];
int N;
vector<int> v;

void dfs()
{
    if (v.size() == N) // ¿ì¹° 
    {
        for (int i = 0; i < v.size(); ++i)
            printf("%d ", v[i]);
        printf("\n");
    }
	 
    for (int i=1; i<=N;i++)
        if (!isVisited[i])
        {
            isVisited[i] = 1;
            v.push_back(i);
            dfs();
            isVisited[i] = 0;
            v.pop_back();
        }
}

int main()
{
    scanf("%d", &N);
    dfs();
}
