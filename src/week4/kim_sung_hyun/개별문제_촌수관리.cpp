#define _CRT_SECURE_NO_WARNINGS 
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<math.h>
using namespace std;

int N, M, K, NM;
bool check[101];
vector<int> arr[101];

int bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(M, 0));
	while (!q.empty())
	{
		int v = q.front().first;
		int dis = q.front().second;
		q.pop();
		if (v == K)
			return dis;
		for (int i = 0; i < arr[v].size(); i++)
		{
			if (!check[arr[v][i]])
			{
				check[arr[v][i]] = true;
				q.push(make_pair(arr[v][i], dis + 1));
			}
		}
	}
	return -1;
}


int main() {
	scanf("%d", &N);
	scanf("%d %d", &M, &K);
	scanf("%d", &NM);
	for (int i = 0; i < NM; i++)
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	printf("%d", bfs());
}