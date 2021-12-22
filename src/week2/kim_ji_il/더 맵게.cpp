/*  # 1번 풀이 (통과)
- 문제 : [더맵게]  
- 접근 방식 : 
	scoville의 길이가 최대 백만이기 때문에 O(n^2) 의 알고리즘으로는 안된다고 판단.
    카테고리가 힙인 만큼 우선순위큐가 바로 떠올라 어렵지 않게 풀 수 있었다.
    1.우선순위큐에 모든 원소 넣고 /  2. 큐의 가장 작은 원소가 K보다 크거나 1개가 남을때까지 반복. / 3. 마지막에 남은 원소가 K보다 작을경우 -1 출력.
- 시간 복잡도 : O(nlogn) 
*/

#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    //O(nlogn)
    for(auto& elem : scoville){
        pq.push(elem);
    }
    
    while(pq.size()>1 && pq.top()<K){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        int new_scoville = first + (second*2);
        pq.push(new_scoville);
        answer++;
    }
 
    if(pq.top()<K) answer = -1;
    
    
    return answer;
}