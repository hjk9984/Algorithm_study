#include <string>
#include <vector>
#include <queue>
using namespace std;

bool check[201];
int result;

void BFSCAL(int start, int n, vector<vector<int>> computers)
{
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if (!check[i] && i != node && computers[node][i] == 1)
			{
				q.push(i);
				check[i] = true;
			}
		}
	}
}


void BFS(int n, vector<vector<int>> computers)
{
	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			result++;
			BFSCAL(i, n, computers);
		}
	}
}




int solution(int n, vector<vector<int>> computers) {

	BFS(n, computers);

	return result;
}