//hash
//공통 문제: 위장

//return 서로 다른 옷의 조합의 수

// #clothes <= 30
// 중복된 옷은 없음
// 스파이는 하루에 최소 한 개의 의상은 입음

#include <string>
#include <vector>
#include <map>
using namespace std;

int ans = 0;

// 풀이: 의상의 종류에 none을 추가
// 예시 1에서 head는 none, hat, turban/ eye는 none, glasses
// 여기서 3 * 2 - 1을 하면 5가 나온다. 
int solution(vector<vector<string>> clothes){
    map<string, int> m;
    int ans = 1;

    //O(n)
    for(auto& e : clothes)
        m[e[1]]++;

    map<string, int>::iterator itr = m.begin();
    for(itr; itr != m.end(); itr++)
        ans *= (itr->second + 1);

    return ans - 1;
}