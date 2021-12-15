//개인 문제
//https://programmers.co.kr/learn/courses/30/lessons/12899

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n>0) {               
        //1, 2, 4 세개의 숫자 중 하나므로 세가지 경우로 나뉠 것을 예상
        if((n+2)%3 == 0) {
            answer = "1" + answer;
            n = n/3; 
        } else if((n+1)%3 == 0) {
            answer = "2" + answer;
            n = n/3; 
        } else if(n%3 == 0) {
            answer = "4" + answer;
            n = n/3 - 1; 
        }
    }
    return answer;
}