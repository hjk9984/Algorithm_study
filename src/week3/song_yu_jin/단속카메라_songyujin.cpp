//탐욕법
//https://programmers.co.kr/learn/courses/30/lessons/42884

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end()); //진입 지점 기준 오름차순 정렬
    
    int out = routes[0][1]; //첫번째 차의 진출 지점
    for(int i=1; i<routes.size(); i++) {
        //앞의 차의 진출 지점이 현재 차의 진입 지점보다 빠르면
        //앞의 차를 위한 카메라 필요
        if(out < routes[i][0]) {
            answer++;
            out = routes[i][1]; //현재 차의 진출 지점으로 갱신
        }
        //앞의 차의 진출 지점보다 현재 차가 먼저 나갈 때
        if(out > routes[i][1]) {
            out = routes[i][1];
        }     
    }
    return answer;
}