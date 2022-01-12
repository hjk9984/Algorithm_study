/*
- 문제 : [타겟 넘버]  
- 접근 방식 : 
recusion으로 풀었다.
( dfs = 그래프 문제 ) 라는 인식이 있어서 그런지 dfs 문제라기 보다는 재귀함수나, 완전 탐색 파트에 나올 문제가 아닌가 싶었다. dfs가 모든 노드를 방문하는 것이기에 같은 말이기도 하다.
- 시간 복잡도 :  
*/
#include <string>
#include <vector>

using namespace std;

int cnt;

void dfs(vector<int>& numbers,int idx,int target){
    
    if(idx== numbers.size()){
        if(target ==0) cnt++;
        return;
    }
    dfs(numbers,idx+1,target - numbers[idx]);
    dfs(numbers,idx+1,target + numbers[idx]);

}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers,0,target); 
    answer =cnt;
       
    return answer;
}