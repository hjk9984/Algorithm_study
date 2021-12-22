//heap
//https://programmers.co.kr/learn/courses/30/lessons/42627

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0; //작업을 수행한 현 시각 - 요청 시간
    int time = 0; //작업을 수행한 현 시각
    
    //조건)하드디스크가 작업을 수행하고 있지 않을 때에는 먼저 요청이 들어온 작업부터 처리합니다.
    //요청 순서대로 정렬
    sort(jobs.begin(), jobs.end());
    
    //제일 먼저 요청 들어온 것 작업 고정
    time = jobs[0][0] + jobs[0][1];
    answer = jobs[0][1];
    
    for(int i=1; i<jobs.size(); i++) {
        //{작업 소요 시간, 작업 인덱스} pair인 우선순위 큐 선언
        //작업 소요 시간이 적은 순서대로(오름차순)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int j=1; j<jobs.size(); j++) {
            //작업 요청 시간이 현 시각보다 작을 때 && 수행하지 않은 작업일 때
            if(jobs[j][0] <= time && jobs[j][0] != -1) {
                pq.push({jobs[j][1], j});
            }
        }
        if(!pq.empty()) {
            time += pq.top().first;
            answer += time - jobs[pq.top().second][0];
            //수행한 작업 체크 용도
            jobs[pq.top().second][0] = -1;
        } else if (jobs[i][0] != -1) {
            //현재 작업이 수행중이지 않을 때
            //요청 순서대로 정렬된 jobs이기 때문에
            time = jobs[i][0] + jobs[i][1];
            answer += jobs[i][1];
            //수행한 작업 체크 용도
            jobs[i][0] = -1;
        }
    }
    
    return answer/jobs.size();
}