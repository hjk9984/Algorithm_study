#include <string>
#include <vector>

#define MAX 1000010
using namespace std;

int DP[MAX];
int DP2[MAX];
int max(int A, int B) { if (A > B) return A; return B; }

int solution(vector<int> money)
{
	int n = money.size() - 1;
	DP[0] = money[0];
	DP[1] = DP[0];
	DP2[0] = 0;
	DP2[1] = money[1];

	for (int i = 2; i < n; i++)
	{
		DP[i] = max(DP[i - 2] + money[i], DP[i - 1]);
	}
	for (int i = 2; i <= n; i++)
	{
		DP2[i] = max(DP2[i - 2] + money[i], DP2[i - 1]);
	}

	return max(DP[n - 1], DP2[n]);
}


