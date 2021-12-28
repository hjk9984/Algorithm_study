#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3);

    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i] == one[i%one.size()]) score[0]++;
        if(answers[i] == two[i%two.size()]) score[1]++;
        if(answers[i] == thr[i%thr.size()]) score[2]++;
    } 
    
    int maxValue  = *max_element(score.begin(),score.end());
    for(int i=0; i<3; i++)
        if(maxValue == score[i]) answer.push_back(i+1);
    
    return answer;
}