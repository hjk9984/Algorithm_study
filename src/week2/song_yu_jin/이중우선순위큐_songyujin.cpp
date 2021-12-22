//heap
//https://programmers.co.kr/learn/courses/30/lessons/42628

#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    priority_queue<int> max_pq; //max heap
    priority_queue<int, vector<int>, greater<int>> min_pq; //min heap
    int cnt = 0;
    for(int i=0; i<operations.size(); i++) {
        string operation = operations[i].substr(0, 1);
        int number = stoi(operations[i].substr(2));
        
        if (operation == "I") {
            max_pq.push(number);
            min_pq.push(number);
            cnt++;
        } else {
            //빈 큐에 데이터를 삭제하라는 연산이 주어질 경우, 해당 연산은 무시
            if (cnt == 0) {
                continue;
            }
            //이중우선순위 큐가 1개일 때 pop 요청하는 것이므로 초기화
            if (cnt == 1) {
                max_pq = priority_queue<int>();
                min_pq = priority_queue<int, vector<int>, greater<int>>();
                cnt = 0;
                continue;
            }
            if (number == 1) {
                max_pq.pop();
                cnt--;
            } else {
                min_pq.pop();
                cnt--;
            }
        }
    }
    if(!max_pq.empty()) {
        answer[0] = max_pq.top(); 
    }
    if(!min_pq.empty()) {
        answer[1] = min_pq.top();
    }
    return answer;
}