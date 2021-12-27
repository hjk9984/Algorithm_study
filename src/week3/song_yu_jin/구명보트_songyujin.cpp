//탐욕법
//https://programmers.co.kr/learn/courses/30/lessons/42885

//풀이 1 --> 테스트 케이스는 정답이나 효율성 0점
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.rbegin(), people.rend()); //몸무게 내림차순 정렬
    int answer = 0;
    while(people.size() != 0) {
        bool able = false;
        for(int j=1; j<people.size(); j++) {
            if(people[0] + people[j] <= limit) {
                able = true;
                people.erase(people.begin());
                people.erase(people.begin() + j-1);
                answer++;
                break;
            }
        }
        if(able == false) {
            people.erase(people.begin());
            answer++; 
        }
    }
    return answer;
}

//풀이 2
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;
    int index = 0; //가장 가벼운 사람 index
    int rindex = people.size()-1; //가장 무거운 사람 index
    while(index <= rindex) {
        if(people[index] + people[rindex] <= limit) {
            index++;
            rindex--;
        } else {
            rindex--;
        }
        answer++;
    }

    return answer;
}