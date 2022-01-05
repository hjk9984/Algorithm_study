// 완탐
// 공통 문제: 모의고사

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> p = {{1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5},
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    int arr[3];

    for(int i=0; i<3; i++){
        int idx = 0;
        int cnt = 0;
        for(auto e: answers){
            if(p[i][idx] == e) cnt++;
            if(++idx >= p[i].size()) idx = 0;
        }
        arr[i] = cnt;
    }
    
    int max_cnt = 0;
    for(int i=0; i<3; i++){
        if(arr[i] > max_cnt){
            max_cnt = arr[i];
            answer.clear();
            answer.push_back(i+1);
        }
        else if(arr[i] == max_cnt){
            answer.push_back(i+1);
        }
    }
    return answer;
}