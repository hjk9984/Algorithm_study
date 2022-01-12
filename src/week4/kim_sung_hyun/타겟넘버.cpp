#include <vector>
#include <string>
#include <iostream>//메인 출력용

using namespace std;

int answer;


void DFS(int cnt, int val, vector<int> numbers, int target)
{
	if (cnt == numbers.size())
	{
		if (val == target)
			answer++;
		return;
	}


	DFS(cnt + 1, val + numbers[cnt], numbers, target);
	DFS(cnt + 1, val - numbers[cnt], numbers, target);
}




int solution(vector<int> numbers, int target) {

	DFS(0, 0, numbers, target);
	return answer;
}