#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define ll long long

int solution(vector<int> scoville, int K) {
    int answer = -1;
    priority_queue<ll> pq;
    for(ll e: scoville)
        pq.push(-e);
    
    ll res = -1, cnt = 0;
    while(!pq.empty()){
        if(-pq.top() >= K){
            answer = cnt;
            break;
        }
        if(pq.size() == 1) break;
        ll a = -pq.top(); pq.pop();
        ll b = -pq.top(); pq.pop();
        res = a + b*2;
        cnt++;
        pq.push(-res);
    }
    
    return answer;
}