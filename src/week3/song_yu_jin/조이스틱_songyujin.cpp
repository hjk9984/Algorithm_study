//탐욕법
//https://programmers.co.kr/learn/courses/30/lessons/42860

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    int length = name.length();
    string str = "";
    for(int i=0; i<name.length(); i++) {
        str += "A";
    }
    
    int i=0;
    while(str != name) {
        //다음, 이전 알파벳 찾기(차이가 작은 방향으로 택함)
        int gap = name[i] - str[i];
        if (gap != 0) {
            if (gap <= 13) {
                answer += gap;
            } else {
                answer += 26 - gap;
            }
            str[i] = name[i];
        }
        if(str == name) {
            break;
        }
        
        //커서 왼쪽 오른쪽 판단하기
        for(int j=1; j<length; j++) {
            //오른쪽으로 가는 커서가 더 먼저 str이랑 다른 문자가 있으면
            if(name[(i+j)%length] != str[(i+j)%length]) {
                i = (i+j)%length;
                answer += j;
                break;
            }
            //왼쪽으로 가는 커서가 더 먼저 str이랑 다른 문자가 있으면
            else if(name[(i+length-j)%length] != str[(i+length-j)%length]) {
                i = (i+length-j)%length;
                answer += j;
                break;
            }
        }
    }
    
    return answer;
}