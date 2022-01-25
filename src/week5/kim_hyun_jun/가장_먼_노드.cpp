#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool visited[20001];
vector<vector<int>> v(20001);

int bfs(int n){
    queue<int> q;
    q.push(1);
    visited[1] = true;
    n--;

    int cnt = 0;
    while(!q.empty()){
        int sz = q.size();
        cnt = 0;
        while(sz--){
            int node = q.front();
            q.pop();
            for(auto e : v[node]){
                if(visited[e]) continue;
                q.push(e);
                visited[e] = true;
                cnt++;
                n--;
            }
        }
        if(n == 0) break;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    for(auto e: edge){
        v[e[0]].push_back(e[1]);
        v[e[1]].push_back(e[0]);
    }

    return bfs(n);
}