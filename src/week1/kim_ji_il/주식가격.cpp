/*  # 1번 풀이 (통과)
- 문제 : [주식가격]
- 접근 방식 : 벡터 말고 다른 자료구조를 사용하지 않고 푼 문제.
            정답 처리는 되는데, prices의 길이가 2 ~ 100,000 이고, 최악의 경우 100,000 이라고 했을때 이중 for문으로는 시간 초과가 분명.
- 시간 복잡도 : O(n^2)
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    int j=0;
    for(int i=0;i<prices.size();i++){
        for(j=i+1;j<prices.size();j++){
            if(prices[i]<=prices[j]){
                answer[i]++;
                }
            else{
                answer[i]++;
                break;
                }
            }
        }
    return answer;
}