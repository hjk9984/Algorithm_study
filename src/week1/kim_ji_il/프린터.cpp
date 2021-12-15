/*  # 1번 풀이 (통과)
- 문제 : [프린터]

*/

#include <string>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<std::pair<int,int>> que;
    
    // 큐에 priorities 랑 location pair로 해서 삽입.
    int index =0;
    for(auto& elem :priorities){
        que.push(make_pair(elem,index));       
        index++;
    }
    // priorities 내림차순 정렬.
    sort(priorities.begin(),priorities.end(),std::greater<int>());
    
    while(!que.empty()){
       if(que.front().first >=priorities[answer]){
           answer++;
           if(location == que.front().second) return answer;
           que.pop();
        }else{
           que.push(que.front());
           que.pop();
        }
    }   
    
    return answer;
}