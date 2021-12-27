//탐욕법
//https://programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    //여벌 채육복을 가져온 학생이 체육복을 도난 당한 경우
    //lost, reserve 배열에서 각각 삭제 시켜준다
    for(int i=0; i<lost.size();) {
        bool find = false;
        for(int j=0; j<reserve.size();) {
            if(lost[i] == reserve[j]) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                find = true;
            } else {
                j++;
            }
        }
        if(find == false) {
            i++;
        }
    }
    
    //lost 학생 중에 reserve 학생에게 체육복을 받을 수 있는 경우
    //lost, reserve 배열에서 각각 삭제 시켜준다 
    for(int i=0; i<lost.size();) {
        bool find = false;
        for(int j=0; j<reserve.size(); j++) {
            if((lost[i] == reserve[j] - 1) || (lost[i] == reserve[j] + 1)) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                find = true;
                break;
            }
        }
        if(find == false) {
            i++;
        }
    }
    
    //답 = 전체 학생 수 - lost 배열의 크기
    return n-lost.size();
}