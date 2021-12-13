//스택/큐
//https://programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> stack;
    
    for (int i=progresses.size()-1; i>=0; i--) {
        stack.push(progresses[i]); //0번째 progresses가 스택의 top에 저장되야하므로 역순으로 스택에 저장
    }
    
    int day = 0; //작업의 진도를 계산하기 위한 변수
    int idx = 0; //stack pop 한 후 stack과 speeds 배열의 크기가 같지 않으므로 idx를 기억하기 위한 변수
    while(!stack.empty()) {
        day++;      
        int top = stack.top() + (day * speeds[idx]); //작업의 진도 = 처음 작업 진도 + (day * 작업의 속도)
        int cnt = 0; //답 저장용 카운트
        if(top >= 100) {//스택의 top 작업이 끝나면
            idx++;
            cnt++;
            stack.pop();

            while(!stack.empty()) {//스택의 top과 같이 작업이 끝날 수 있는 경우 판단
                top = stack.top() + (day * speeds[idx]);
                if (top < 100) {
                    break;
                } else {
                    idx++;
                    cnt++;    
                    stack.pop();
                }
            }    
            answer.push_back(cnt);
        }
    }
    
    return answer;
}