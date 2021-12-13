//스택/큐
//https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> passing; //다리를 건너는 트럭
    stack<int> waiting; //대기 트럭
    
    for(int i=truck_weights.size()-1; i>=0; i--) {
        waiting.push(truck_weights[i]);
    }
    
    int kg = 0; //다리를 건너는 트럭들의 총 무게
    while(!waiting.empty()) {
        answer++;
        
        if(kg + waiting.top() <= weight) { //다리에 진입 가능          
            passing.push(waiting.top());
            kg += waiting.top();
            waiting.pop();
        } else {
            //다리에 진입 불가능,
            //해당 처리를 안하면 조건1)에 부합하지 않는 경우 생기기 때문에 다리에 진입 불가능한 경우 passing 큐 사이즈 증가시켜야함
            passing.push(0);
        }
        
        if(passing.size() == bridge_length) {//조건1) 다리에 올라갈 수 있는 최대 트럭의 수 도달 시 pop
            kg -= passing.front();
            passing.pop();
        }
    }
    answer += bridge_length; //waiting.empty() 일때 while 문이 끝나기 때문에 마지막 트럭이 다리를 건너는 시간을 더해줌
    return answer;
}