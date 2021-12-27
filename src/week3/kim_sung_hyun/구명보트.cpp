#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}



int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), cmp);
    int size = people.size();
    int minValue = people[size-1];
    int idx=size-1;
    for(int i=0; i<idx+1; i++)
    {
        int tempSize = limit - people[i];
        answer++;
        if(tempSize < minValue)
            continue;
       // cout << tempSize << endl;
        if(tempSize >= people[idx])
            idx--;
    }
    return answer;
}