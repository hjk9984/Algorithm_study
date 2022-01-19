#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<iostream>
#include<string.h>
#include<queue>


using namespace std;
int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool>> v(n + 1, vector<bool>(n + 1, false));

	for (auto r : results)
	{
		v[r[0]][r[1]] = true;
	}

	for (size_t i = 1; i < n + 1; i++)
	{
		for (size_t j = 1; j < n + 1; j++)
		{
			for (size_t k = 1; k < n + 1; k++)
			{
				if (v[j][i] && v[i][k])
				{
					v[j][k] = true;
				}
			}
		}
	}

	for (size_t i = 1; i < n + 1; i++)
	{
		int result = 0;
		for (size_t j = 1; j < n + 1; j++)
		{
			if (v[i][j] || v[j][i])
				result++;
		}
		if (result == n - 1)
			answer++;
	}


	return answer;
}