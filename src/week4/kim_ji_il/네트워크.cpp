/*
- 문제 : [네트워크]  
- 접근 방식 : 
    그래프가 인접리스트가 아닌 인접행렬로 주어졌고, 0번 컴퓨터부터 dfs 돌린 다음에 아직 visited이     false 인 컴퓨터가 있다면 네트워크 개수(answer++) 해주고 다시 dfs 
- 시간 복잡도 :  O(n^2)
*/
#include <string>
#include <vector>

using namespace std;
bool visited[201];

void dfs(int cur,vector<vector<int>>& computers){
    visited[cur]=true;
    
    for(int i=0;i<computers.size();i++){
        if(computers[cur][i]!=0 && !visited[i]){
            dfs(i,computers);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    dfs(0,computers);
    answer++;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            answer++;
            dfs(i,computers);
        }
    }
    
    return answer;
}