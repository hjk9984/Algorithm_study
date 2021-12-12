//해시
//https://programmers.co.kr/learn/courses/30/lessons/42578
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> map; //순서는 상관 없고, key: 옷 종류, value: 옷 이름의 map 생성 필요
    
    //clothes[i][1] : 옷 종류
    //하나의 옷 종류에 여러개의 옷이 존재하므로 ++1
    for(int i=0; i<clothes.size(); i++) {
        map[clothes[i][1]]++;
    }
    
    //(it->second : 한개의 옷 종류에 존재하는 옷들의 갯수) + (1 : 입지 않는 경우)
    for(auto it =map.begin(); it != map.end(); it++){
        answer *= (it->second + 1); 
    }
    
    //최소 한개의 의상을 입는 조건 존재하여 -1
    return answer-1;
}