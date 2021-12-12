// hash
// 공통 문제: 완주하지 못한 선수

// return 완주하지 못한 선수의 이름

// #com = #p - 1
// #name <= 20
// 동명이인이 있을 수 있다.

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 풀이 1: unordered map 해시 사용하기
// 중복된 값이 있을 수 있으므로 count를 value로 가져감
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> s;

    //O(n)
    for(auto& elem : completion)
        s[elem]++;

    //O(n)
    //count를 이용하면 key의 개수가 나오는 것이 아닌 키의 존재를 나오게 함
    for(auto& elem : participant){
        if(s[elem])
            s[elem]--;
        else
            return elem;
    }

    return participant[participant.size()-1];
}



// 풀이 2: 그저 정렬을 하여 확인하기
// n이 100,000이므로 nlogn으로도 해결 가능하다고 생각
string solution1(vector<string> participant, vector<string> completion) {
    string answer = "";
    //O(nlogn)
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    //O(n)
    for(int i=0; i<completion.size(); i++){
        if(participant[i] != completion[i]){
            answer = participant[i];
            return answer;
        }
    }

    return participant[participant.size()-1];
}