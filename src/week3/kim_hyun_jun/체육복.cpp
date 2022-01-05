//완탐, 그리티
//공통 문제: 체육복

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
bool arr[35] = {};

//풀이 1: 벡터 사용
//처음에 정렬하고 여벌을 가지고 있지만 도난당한 학생을 처리한 후
//lost를 처리하려고 함
//생각한 알고리즘은 맞았지만 5번 케이스가 계속 틀렸고
// 이틀동안 붙잡고 생각해보니 아래 주석이 틀렸다

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for(auto e: reserve)
        arr[e] = true;
    

    // 처음 풀때 사용한것
    // 루프를 돌면서 lost를 삭제하니 인덱스가 바뀌었을 게 확실....
    // for(int i=0; i<lost.size(); i++){
    //     if(arr[lost[i]]){
    //         arr[lost[i]] = false;
    //         lost.erase(lost.begin() + i);
    //     }
    // }

    vector<int> idxs;
    for(int i=0; i<lost.size(); i++){
        if(arr[lost[i]]){
            arr[lost[i]] = false;
            idxs.push_back(i);
        }
    }

    for(int i=idxs.size()-1; i>=0; i--){
        lost.erase(lost.begin() + idxs[i]);
    }
    
    for(auto e: lost){
        bool lent = false;
        for(int i=e-1; i<=e+1; i++){
            if(i == 0 || i > n) continue;
            if(arr[i]){
                arr[i] = false;
                lent = true;
                break;
            }
        }
        if(!lent) answer--;
    }

    return answer;
}

//풀이 2: 위와 동일하지만 set을 이용
int solution1(int n, vector<int> lost, vector<int> reserve){
    set<int> ls(lost.begin(), lost.end()), rs(reserve.begin(), reserve.end());
    set<int> ls1(ls);

    for(auto e : rs){
        set<int>::iterator itr = ls.find(e);
        if(itr != ls.end()) ls.erase(itr);
    }

    for(auto e : ls1){
        set<int>::iterator itr = rs.find(e);
        if(itr != rs.end()) rs.erase(itr);
    }

    for(auto e : rs){cout << e << " ";}
    cout << endl;
    for(auto e : ls){cout << e << " ";}
    cout << endl;

    for(auto e: rs){
        int f = e - 1;
        int b = e + 1;
        if(ls.find(f) != ls.end()){
            ls.erase(ls.find(f));
        }
        else if(ls.find(b) != ls.end()){
            ls.erase(ls.find(b));
        }
    }
    cout << ls.size() << endl;
    return n - ls.size();
}