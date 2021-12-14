//스택 큐
//공통 문제: 주식가격
//https://programmers.co.kr/learn/courses/30/lessons/42584?language=cpp

//return 가격이 떨어지지 않은 기간이 몇 초인지

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> st;
vector<vector<int>> v(10005);

//풀이 1: prices의 길이가 최대 100,000이므로 n^2으로 풀면 안된다고 생각
//2차원 vector에 가격별로 인덱스를 저장하고 스택에 가격을 오름차순으로 쌓았다.
//top보다 작은 값이 나오면 pop을 하고 벡터에 저장된 인덱스를 계산하는 방식을 사용.

vector<int> solution(vector<int> prices) {
    //ans에 push back보다는 인덱스로 넣을 거기 때문에 가격 크기로 초기화
    vector<int> answer(prices.size());

    //O(n)
    for(int i=0; i<prices.size(); i++){
        int n = prices[i];
        // 다음 가격에 따른 처리
        while(!st.empty()){
            if(n > st.top()){
                st.push(n);
                v[n].push_back(i);
                break;
            }
            else if(n < st.top()){
                for(auto idx:v[st.top()]){
                    answer[idx] = i-idx;
                }
                v[st.top()].clear();
                st.pop();
            }
            else {
                v[n].push_back(i);
                break;
            }
        }
        if(st.empty()){
            st.push(n);
            v[n].push_back(i);
        }
    }

    //끝까지 다 돌고 스택에 남아 있는 얘들 처리
    for(auto e: v){
        for(auto idx: e){
            answer[idx] = prices.size() - idx -1;
        }
    }

    return answer;
}

//풀이 2(다른 사람 풀이): 스택에 가격이 아닌 인덱스 올리기
//인덱스를 스택에 넣을 생각은 못했다...
vector<int> solution1(vector<int> prices) {
    vector<int> ans(prices.size());
    stack<int> s;

    for(int i=0; i<ans.size(); i++){
        //알아 둘 점: s가 비워있으면 어차피 s.top()는 하지 않음
        while(!s.empty() && prices[s.top()]>prices[i]){
            ans[s.top()] = 1-s.top();
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty()){
        ans[s.top()] = ans.size() - s.top()-1;
        s.pop();
    }
    return ans;
}

int main(){

    stack<int> tmp;
    if(tmp.top() && !tmp.empty()) cout << "ok";
}