//해시
//https://programmers.co.kr/learn/courses/30/lessons/42576

//풀이방법1
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i=0; i<participant.size(); i++){ //참가자, 완주자 모두 정렬했으므로 포문 한개로 비교 가능
        if(participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }
    return answer;
}

//풀이방법2
//set : map과 구조가 매우 유사하며 key만 있고 value가 없는 map
//unordered_map을 사용하려 했으나 key(=참가자명) 에 대한 value 값이 필요 없어보여 set 사용
//참가자명에 중복된 이름이 있으므로 multiset 사용
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> set;
    
    for (int i=0; i<participant.size(); i++) {
        set.insert(participant[i]);
    }
    for (int i=0; i<completion.size(); i++) { //참가자명이 들어있는 set 컨테이너에서 완주자명 erase
        set.erase(set.find(completion[i]));
    }
    
    return *set.begin();
}