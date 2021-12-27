#include<iostream>
#include<vector>
#include<string>


using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
    int student[31]={0,};
    for (int i = 0; i < reserve.size(); i++)
	{
		student[reserve[i]] = 1;
	}

	for (int i = 0; i < lost.size(); i++)
	{
		student[lost[i]]--;
	}



	for (int i = 1; i <= n; i++)
	{
		if (student[i] == -1)
		{
			if (student[i - 1] == 1) //체육복이 많아 얘 빌릴곳이 나밖에없어 그럼 빌려
			{
				student[i]=0;
				student[i - 1]=0;
			}
			else if (student[i + 1] == 1)
			{
				student[i]=0;
				student[i + 1]=0;
			}
		}
	}


	for (size_t i = 1; i <= n; i++)
	{
		if (student[i] >= 0)
			answer++;
	}
    
    // 앞부터 가져오고 없으면 뒤를 끝까지 반복한다.

	return answer;
}