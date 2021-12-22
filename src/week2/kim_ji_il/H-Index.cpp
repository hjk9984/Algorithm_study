/*  # 1번 풀이 (통과)
- 문제 : [ H-Index ]  
- 접근 방식 : 
	처음에 문제가 이해 되지 않아서 헤맸으나 정렬 파트라는 점을 생각해서 내림차순 정렬해보니 값의 관계를 알 수 있었다.
- 시간 복잡도 : O(nlogn) ?
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end(),greater<int>());
    
    for(int i=0;i<citations.size();i++){
        if(citations[i]>=i+1) answer = i+1;
        else break;
    }
    
    return answer;
}