#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;


bool cmp(vector<int> a, vector<int> b)
{
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

struct compare{
    bool operator()(pair<int,int> a , pair<int,int> b)
    {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
    
};


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>,compare> pq;
    
    //jobs 작업 요청되는 시점기준 sort
    sort(jobs.begin(),jobs.end(),cmp);
    
    int idx=0;
    int time=0;
    
    //아래가 while문으로
    while(true)
    {
       // cout << time << "idx = " << idx << endl;
        int tempIdx = idx;
        for(int i = tempIdx; i < jobs.size(); i++)
        {
            if(jobs[i][0] <= time)
            {
                pq.push({jobs[i][0],jobs[i][1]});
                idx++;
            }
        }
        
        //현재 디스크가 비었으면 idx이용해서 그냥 넣음
        if(pq.empty())
        {
            time = jobs[idx][0] + jobs[idx][1];
            answer += time - jobs[idx][0];
            idx++;
        }
        
        //time 매겨변수 이용해서 index부터 끝까지 time >= 작업이 요청되는 시점 인 경우 pq에 넣음 idx조절함
        

        
       // cout << "2time = " <<time << "idx = " << idx << endl;

        if(!pq.empty())
        {
            int firstTime = pq.top().first;
            int secondTime = pq.top().second;
            time = time + secondTime;
            answer += time - firstTime;
            pq.pop();
        }
        if(idx == jobs.size() && pq.empty())
        {
            break;
        }
    }
    return answer/jobs.size();
}