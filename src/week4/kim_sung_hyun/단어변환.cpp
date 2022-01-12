#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int answer;


bool checkWord(string begin, string str)
{
	int cnt = 0;
	for (int i = 0; i < begin.size(); i++)
		if (begin[i] == str[i])
			cnt++;
	if (cnt == begin.size() - 1)
		return true;
	return false;
}

int BFSCAL(int val, string target, vector<string> words)
{
	bool check[51] = { 0, };
	queue<pair<int, int>> q;
	q.push({ val,1 });
	check[val] = true;
	while (!q.empty())
	{
		int node = q.front().first;
		int cnt = q.front().second;
		q.pop();
		//cout << node << " " << cnt << endl;
		for (int i = 0; i < words.size(); i++)
		{
			if (!check[i] && checkWord(words[node], words[i]))
			{
				if (words[i] == target)
					return cnt + 1;
				check[i] = true;
				q.push({ i,cnt + 1 });
			}
		}
	}
	return 100;
}

void BFS(string begin, string target, vector<string> words)
{
	for (int i = 0; i < words.size(); i++)
	{
		if (checkWord(begin, words[i]))
		{
			// cout << "reset" << endl;
			if (words[i] == target)
				answer = 1;
			else
			{
				int temp = BFSCAL(i, target, words);
				if (temp < answer)
					answer = temp;
			}
		}
	}
}


int solution(string begin, string target, vector<string> words) {
	answer = 100;
	BFS(begin, target, words);
	if (answer == 100)
		return 0;
	else
		return answer;
}