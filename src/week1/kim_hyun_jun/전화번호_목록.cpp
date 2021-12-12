// hash
// 공통 문제: 전화번호 목록

// return 어떤 번호가 다른 번호의 접두어인지 아닌지

// #book <= 1,000,000
// 전화번호 중복x

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

//풀이1: 무지성 다 비교하기
//set에 다 넣은 다음 
//book에 있는 번호들을 한자리씩 추가한 접두어가 set에 있는 지 확인
bool solution(vector<string> phoneBook){
    unordered_set<string> s;

    //O(n)
    for(auto& e : phoneBook)
        s.insert(e);
    
    //O(n), 전화번호의 길이가 최대 20이니 시간복잡도에 크게 영향x
    for(auto& e : phoneBook){
        string tmp = "";
        for(int i=0;i<e.size();i++){
            tmp += e[i];
            if(s.count(tmp) && tmp != e)
                return false;
        }
    }

    return true;
}


//풀이2: set에 넣기
//set에 넣으면 정렬이 되기 때문에
//만약 접두어 관계가 있다면 붙어 있을 거라고 생각
//잘못된 생각: iterator는 증감연산자는 되지만 +-는 안됨
//임의 점근 가능한 iterator만 가능 ex) tmp[3]
//https://stackoverflow.com/questions/1033089/can-i-increment-an-iterator-by-just-adding-a-number/1033097

//so, 그냥 벡터 정렬을 해봄
bool solution2(vector<string> phoneBook){
    #define pb phoneBook
    sort(pb.begin(), pb.end());

    for(int i=0; i<pb.size()-1; i++){
        if(pb[i+1].size() < pb[i].size()) continue;

        int tmp = 0;
        for(int j=0; j<pb[i].size(); j++){
            if(pb[i][j] != pb[i+1][j]) break;
            tmp++;
        }

        if(tmp == pb[i].size()) return false;

    }

    return true;
}

//새로 알게된 점
// set<string>::iterator itr = s.begin(); itr+1;
// 위의 연산은 임의 접근이 가능한 stl만 가능 vector는 가능

// 문자열 하나하나 비교하지 말고 substr사용하기
// str == str1.substr(0, str.size())