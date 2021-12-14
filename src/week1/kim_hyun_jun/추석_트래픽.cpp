#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//풀이: 오랜만에 캐스팅이라 좀 헷갈렸다.
//string에서의 형변환들을 잊지말자, stoi
class Time{
public:
    int start, end;
    int term;

    //int 값 제한을 넘지 않을 거라 생각해서 int로 받았고
    //소수점도 1000을 곱하고 int형 변수에 넣어서 정수로 처리함
    Time(string str){
        int hour =  stoi(str.substr(11, 13));
        int min =  stoi(str.substr(14, 16));
        int sec =  stoi(str.substr(17, 19));
        int ms =  stoi(str.substr(20, 23));
        term = stod(str.substr(24, str.size()-1)) * 1000;

        end = hour*3600000 + min*60000 + sec*1000 + ms;
        start = end - term + 1;
    }
};

int solution(vector<string> lines) {
    int answer = 0;
    int per = 999;

    vector<Time> v;
    for(const auto& e: lines){
        v.push_back(Time(e));
    }

    //1초 동안의 처리를 위해 per이라는 변수를 쓰고
    //매 라인의 끝 시간에서 부터 1초 동안의 처리 수를 계산
    // O(n)
    for(int i=0; i<v.size(); i++){
        int cnt = 0;
        int per_start = v[i].end;
        int per_end = v[i].end + per;

        for(int j=0; j<v.size(); j++){
            if(v[j].start <= per_end && v[j].end >= per_start)
                cnt++;
        }
        answer = max(cnt, answer);

    }

    return answer;
}
