//heap
//https://programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //min heap 선언
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while(pq.size() >=2 && pq.top() < K) {
        answer++;
        
        int mix = pq.top();
        pq.pop();
        mix += (pq.top()*2);
        pq.pop();
        
        pq.push(mix);
    }
    
    if(pq.top() < K) {
        answer = -1;
    }
    
    return answer;
}