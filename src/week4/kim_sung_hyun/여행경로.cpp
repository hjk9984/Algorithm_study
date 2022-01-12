#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check[10001];
vector<vector<string>> temp;

void DFS(vector<vector<string>> tickets, int cnt, string dest, vector<string> gil)
{
	if (cnt == tickets.size())
	{
		gil.push_back(dest);
		temp.push_back(gil);
		return;
	}


	for (int i = 0; i < tickets.size(); i++)
	{
		if (!check[i] && tickets[i][0] == dest)
		{
			check[i] = true;
			vector<string> tmp;
			for (int k = 0; k < gil.size(); k++)
				tmp.push_back(gil[k]);
			tmp.push_back(dest);
			DFS(tickets, cnt + 1, tickets[i][1], tmp);
			check[i] = false;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	sort(tickets.begin(), tickets.end());
	vector<string> tmp;
	DFS(tickets, 0, "ICN", tmp);
	return temp[0];
}