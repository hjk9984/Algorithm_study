//정렬
//https://programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++) {
        int start = commands[i][0]-1;
        int end = commands[i][1];
        int index = commands[i][2]-1;
        
        //1. i번째 숫자부터 j번째 숫자까지 자른다 = array의 i~j 범위를 이용해 배열을 초기화
        vector<int> tmpArray(array.begin()+start, array.begin()+end);
        sort(tmpArray.begin(), tmpArray.end());
        answer.push_back(tmpArray[index]);
    }
    return answer;
}