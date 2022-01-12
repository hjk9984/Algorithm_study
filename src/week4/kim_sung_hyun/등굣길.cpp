#include <string>
#include<cstring>
#include <vector>
#include<iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int map[101][101] = { 0, };
	int dp[101][101];

	for (int i = 0; i < puddles.size(); i++)
		map[puddles[i][1]][puddles[i][0]] = -1;

	dp[1][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == -1)
			{
				dp[i][j] = 0;
				continue;
			}

			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000007;
		}
	}

	return dp[n][m];


}