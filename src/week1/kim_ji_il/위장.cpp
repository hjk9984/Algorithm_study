/*  # 1번 풀이 (통과)
- 문제 : [위장]
- 접근 방식 : 처음에는 모든 조합을 구할 생각에 어렵게 생각 했는데, 개수만 계산해주면 되는 문제임을 알고는 쉽게 풀 수 있었다.
             hash_map에 종류별 옷 개수를 count 해주고, 선택안함 포함해서 옷 종류별 개수 +1 를 곱해주면 정답 ( 마지막에 모두 선택 안한 경우 : -1)
- 시간 복잡도 : O(n)
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;    
    
int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string,int> hash_map;
    
    for(size_t i=0;i<clothes.size();i++){
        hash_map[clothes[i][1]]++;
    }
    
    answer=1;
    for(auto elem:hash_map){
        answer *= (elem.second+1);
    }
   
    return answer-1;
}