#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<int> p1 = {1, 2, 3, 4, 5};
vector<int> p2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> correct_cnt = {0, 0, 0};
    // vector<int> correct_cnt(3, 0);
    
    for(int i = 0; i < answers.size(); i++) {
        if (answers[i] == p1[i%5]) {correct_cnt[0]++;}
        if (answers[i] == p2[i%8]) {correct_cnt[1]++;}
        if (answers[i] == p3[i%10]) {correct_cnt[2]++;}
    }
    
    int max = INT_MIN;
    for (int i = 0; i < correct_cnt.size(); i++) {
        if (max <= correct_cnt[i]) {
            max = correct_cnt[i];
        }
    }
    for (int i = 0; i < correct_cnt.size(); i++) {
        if (max == correct_cnt[i]) {
            answer.push_back(i+1);
        }
    }
    /* sort(answer.begin(), answer.end()); 
    어차피 위 for문에서 순서대로 넣고 있기 때문에 필요 없구나 */
    return answer;
}