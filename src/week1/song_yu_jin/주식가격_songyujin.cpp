//스택/큐
//https://programmers.co.kr/learn/courses/30/lessons/42584

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    
    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++) {
            if(prices[i] <= prices[j]) {
                answer[i]++;
            } else {
                answer[i]++; //바로 다음 초에 가격이 떨어져도 1초동안 떨어지지 않은 것이므로
                break;
            }          
        } 
    }
    
    return answer;
}