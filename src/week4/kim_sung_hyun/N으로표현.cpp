#include <vector>
#include <string>
#include <iostream>//메인 출력용
#include<algorithm>
#include<queue>
using namespace std;

int answer;

void DFS(int N, int cnt, int val, int number)
{

	if (number == val)
	{
		if (answer > cnt)
			answer = cnt;
		return;
	}

	if (cnt >= 9)
		return;

	int nextVal = 0;

	for (int i = 0; cnt + i < 9; i++)
	{
		nextVal = 10 * nextVal + N; //i가 한바퀴 돌았다는건 55가 됐다는거 -> 5를 두번 체크해야된다는거
		DFS(N, cnt + i + 1, val + nextVal, number);
		DFS(N, cnt + i + 1, val - nextVal, number);
		DFS(N, cnt + i + 1, val*nextVal, number);
		DFS(N, cnt + i + 1, val / nextVal, number);

	}


}

int solution(int N, int number) {
	answer = 9;
	DFS(N, 0, 0, number);

	if (answer > 8)
		return -1;
	return answer;
}