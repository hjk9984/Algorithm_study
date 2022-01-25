#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int> > graph(n+1);
    vector<int> dist(n+1, -1);
    queue<int> q;

    
    for(int i=0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    dist[1] = 0;
    q.push(1);

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for(int next : graph[current]) {
            if (dist[next]== -1) {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }

    int distance = *max_element(dist.begin(), dist.end());

    for(int i=0; i < dist.size(); i++) {
        if (dist[i] == distance) {
            answer++;
        }
    }
        
    return answer;
}
