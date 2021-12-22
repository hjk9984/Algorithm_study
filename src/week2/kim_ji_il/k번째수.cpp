/*  # 1번 풀이 (통과)
- 문제 : [ k번째 수 ]  
- 접근 방식 : 
	i~j만큼 temp 배열로 만들어주고 sort해서 k번째 원소 가지고 오기.
- 시간 복잡도 : O(nlogn) ?
*/

#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(size_t i=0;i<commands.size();i++){
        vector<int> temp(array.begin()+commands[i][0]-1,array.begin()+commands[i][1]);
       
        sort(temp.begin( ),temp.end()); //O(nlogn)
        answer.push_back(temp[commands[i][2]-1]);
    }
   
    
    
    return answer;
}