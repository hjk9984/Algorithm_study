//스택/큐
//https://programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q; //문서 위치 - 우선순위 pair 인 큐 생성(location 비교를 위해 pair로)
    //큐는 순회를 못하기 때문에 priorities 벡터를 이용해 비교를 하도록 구현함
    //priorities 벡터는 항상 일정하다
    //큐의 맨 처음 문서와 priorities 벡터를 이용해 나머지 문서들의 우선순위 비교를 할때 이미 출력한 문서는 비교하면 안되므로 map 사용
    unordered_map<int, bool> map;
    int size = priorities.size();
    
    for (int i=0; i<size; i++){
        q.push(make_pair(i, priorities[i]));
    }
    
    for (int i=0; i<size; i++){
        map[i] = false;
    }

    int index = 0;//출력된 순서 기억
    while(!q.empty()) {
        bool change = false;
        int priority = q.front().second;//큐의 맨 처음 문서의 우선순위
        
        for (int i=0; i<size; i++){//큐의 맨 처음 문서의 우선순위와 다른 문서들의 우선순위 비교
            if (priority < priorities[i] && map[i] == false) {//큐의 맨 처음 문서의 우선순위보다 높은 우선순위가 있고 + 그 높은 우선순위의 문서가 아직 출력되지 않았다면
                q.push(q.front());//젤 마지막으로 큐 push
                q.pop();
                change = true;
                break;
            }
        }
        if(change == false) {
            index++;
            if(location == q.front().first) {
                return index;
            }
            map[q.front().first] = true;
            q.pop();
        }
    }
    
    return size;
}