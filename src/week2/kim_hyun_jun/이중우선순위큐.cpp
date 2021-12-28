#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;

    for(auto &e: operations){
        if(e[0] == 'I'){
            int tmp = stoi(e.substr(2, e.size()-2));
            v.push_back(tmp);
            sort(v.begin(), v.end());
        }
        else if(e[0] == 'D'){
            if(!v.empty()){
                int tmp = stoi(e.substr(2, e.size()-2));
                if(tmp == 1) v.pop_back();
                else v.erase(v.begin());
            }
        }
    }

    if(v.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(*(v.end()-1));
        answer.push_back(*v.begin());
    }

    return answer;
}



vector<int> solution(vector<string> arguments) {
    vector<int> answer = {0, 0};
    set <int> pq;
    for (auto s : arguments){
        if (s[0] == 'I'){
            int num = stoi(s.substr(2, s.size()));
            pq.insert(num);
        }
        else{
            if (s[2] == '1'){
                auto it = pq.end();
                if (it != pq.begin()){
                    it--;
                    pq.erase(it);
                }
            }
            else{
                auto it = pq.begin();
                if (it != pq.end()){
                    pq.erase(it);
                }
            }
        }
    }
    if (pq.size() > 0){
        answer[0] = *pq.rbegin();
        answer[1] = *pq.begin();
    }
    return answer;
}
