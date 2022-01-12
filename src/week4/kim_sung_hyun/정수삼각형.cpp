#include <string>
#include <vector>

using namespace std;


// tra[i][j] = tra[i-1][j] , tra[i-1][j]

//양쪽 끝은 그냥 더하면댐
// 가운데는 max(dp[i-1][j-1],dp[i-1][j])

int solution(vector<vector<int>> triangle) {
	int dp[501][501] = { 0, };
	int answer = 0;
	dp[0][0] = triangle[0][0];

	for (int i = 1; i < triangle.size(); i++)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			if (j == 0)
				dp[i][j] = triangle[i][j] + dp[i - 1][j];
			if (j == triangle[i].size() - 1) // 맨 오른쪽 처리
			{
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else
				dp[i][j] = triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);

			if (i == triangle.size() - 1)
			{
				if (answer < dp[i][j])
					answer = dp[i][j];
			}
		}


	}

	return answer;
}