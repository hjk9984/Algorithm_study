//완전탐색
//https://programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    int one[5] = {1, 2, 3, 4, 5};
    int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> score(3);
    vector<int> answer;
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == one[i%5]) {
            score[0]++;
        }
        if(answers[i] == two[i%8]) {
            score[1]++;
        }
        if(answers[i] == three[i%10]) {
            score[2]++;
        }
    }
    int max = score[0];
    int max_index = 0;
    for(int i=0; i<3; i++) {
        if(max < score[i]) {
            max = score[i];
            max_index = i;
        }
    }
    answer.push_back(max_index+1);
    for(int i=max_index+1; i<3; i++) {
        if(max == score[i]) {
            answer.push_back(i+1);
        }
    }
    //c++ STL에 max 값을 찾는것 존재
    // int max = *max_element(score.begin(), score.end());
    // for(int i=0; i<3; i++) {
    //     if(max == score[i]) {
    //         answer.push_back(i+1);
    //     }
    // }
    return answer;
}