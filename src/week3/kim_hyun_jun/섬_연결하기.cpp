// greedy
// 공통문제: 섬 연결하기

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 풀이: 처음에 크루스칼이 기억이 안나서 boolean array visit을 만들고
// 다 확인하는 코드를 짰지만 사이클을 확인을 못했다.
// 결국 크루스칼 알고리즘을 확인하고 풀었다.
int arr[101];

bool compare(const vector<int> &a, const vector<int> &b){
    return a[2] < b[2];
}

// 자신의 부모 노드를 리턴하는 함수
int getPar(int num) {
    if(arr[num] == num) return num;
    return arr[num] = getPar(arr[num]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0; i<n; i++) arr[i] = i;
    sort(costs.begin(), costs.end(), compare);

    // 부모 노드를 계속 갱신함
    for(int i=0; i<costs.size(); i++){
        int start = getPar(costs[i][0]);
        int end = getPar(costs[i][1]);
        int cost = costs[i][2];

        if(start != end){
            answer += cost;
            arr[end] = start;
        }
    }
    return answer;
}