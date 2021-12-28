#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

struct work{
    int req, time;

    work(int req, int time): req(req), time(time) {}
};

struct cmp{
    bool operator()(work a, work b){
        if(a.req == b.req)
            return a.time > b.time;
        else
            return a.req > b.req;
    }
};

struct time_cmp{
    bool operator()(work a, work b){
        return a.time > b.time;
    }
};


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<work, vector<work>, cmp> pq;

    for(auto e: jobs){
        pq.push(work(e[0], e[1]));
    }
    
    int cur_time = 0, sum_time = 0;
    while(!pq.empty()){
        if(pq.top().req > cur_time){
            work tmp = pq.top(); pq.pop();
            sum_time += tmp.time;
            cur_time = tmp.time + tmp.req; 
        }
        else{
            priority_queue<work, vector<work>, time_cmp> tpq;
            while(!pq.empty()){
                if(pq.top().req > cur_time) break;
                tpq.push(pq.top());
                pq.pop();
            }
            work tmp = tpq.top();
            tpq.pop();
            sum_time += tmp.time + cur_time - tmp.req;
            cur_time += tmp.time;
            
            while(!tpq.empty()){
                pq.push(tpq.top());
                tpq.pop();
            }
        }
    }
    
    answer = sum_time / jobs.size();
    
    return answer;
}