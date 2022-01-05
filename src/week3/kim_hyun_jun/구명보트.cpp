// greedy
// 공통 문제: 구멍보트

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define people p


int solution(vector<int> people, int limit) {
    int answer = 0;
    stack<int> st;
    sort(people.begin(), people.end());

    int r = people.size()-1;
    while(0 < r){
        int cur = p[0] + p[r];
        if(cur > limit){
            r--;
        }
        else{
            p.erase(p.begin()+r);
            p.erase(p.begin());
            r -= 2;
            answer++;
        }
    }

    answer += p.size();
    return answer;
}



int solution1(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int l = 0, r = people.size()-1;
    while(l < r){
        int cur = p[l] + p[r];
        if(cur > limit){
            r--;
        }
        else{
            l++;
            r--;
            answer++;
        }
    }

    answer += p.size() - answer*2;
    return answer;
}