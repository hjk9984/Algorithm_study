/*
- 문제 : [단어변환]  
- 접근 방식 : 
    단어의 차이가 1개 일때 queue 에 담고 bfs.
    map을 사용하여 단어의 bfs depth를 카운트 해줬다.
- 시간 복잡도 : 
*/
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

queue<string> que;
map<string,int> visited;

bool compare(string a, string b){
    int hit_cnt =0;
    for(int i=0;i<a.length();i++){
        if(a[i]==b[i]) hit_cnt++;
    }
    return a.length()-1 == hit_cnt;
}

int solution(string begin, string target, vector<string> words) {
    
    // words에 target이 없으면 return 0;
    auto itr = std::find(words.begin(),words.end(),target);
    if(itr ==words.end()) return 0;
    
    int answer = 0;
    
    que.push(begin);
    visited[begin]=0;
    
    while(!que.empty()){
        string cur = que.front();
        if(cur == target ) return visited[cur];
        
        que.pop();
        
        for(int i =0;i<words.size();i++){
           if(compare(cur,words[i]) && !visited[words[i]]){  // 단어가 1빼고 전부 일치하고 방문하지 않았다면
                que.push(words[i]);
                visited[words[i]] = visited[cur]+1;
                // words.erase(words.begin() + i);  <<< 있어도 되고 없어도 되고.
            }     
        }
    }
    
    
    return answer;
}