#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    int pCnt = prices.size();
    vector<int> answer(pCnt);
    stack<pair<int,int>> s;
    s.push({prices[0],0});
    for(int i=1; i<prices.size(); i++)
    {
        while(s.top().first > prices[i])
        {
            answer[s.top().second] = i-s.top().second;
            s.pop();
            if(s.empty())
                break;
        }
        s.push({prices[i],i});
    }
    
    while(!s.empty())
    {
        answer[s.top().second] = pCnt-1-s.top().second;
        s.pop();
    }
    
    answer[pCnt-1] = 0;
    return answer;
}