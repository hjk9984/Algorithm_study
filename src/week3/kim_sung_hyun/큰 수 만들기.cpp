#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;


string solution(string number, int k) {
	string answer = "";
	int outputsize = number.size() - k;
	int idx = 0;
	for (int i = 0; i <outputsize; i++)
	{
		char max_v = 0;
		for (size_t j = idx; j <= number.size()-outputsize + i; j++)
		{
			if (max_v < number[j])
            {
                idx = j+1;
				max_v = number[j];
            }
		}
		answer += max_v;
	}

	return answer;
}