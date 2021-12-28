// gold 2
// 개인 문제: 보석도둑
// https://www.acmicpc.net/problem/1202

// 컵라면 문제와 비슷하다.
// 어떤 가방에 먼저 넣을 지 생각하는 것이 중요
// 제일 수용 가능 무게가 적은 가방부터 채우기 시작함으로써
// 제일 가격 합이 크도록 함
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> jv(N);
    vector<int> bv(K);

    for(int i=0; i<N; i++) cin >> jv[i].first >> jv[i].second;
    for(int i=0; i<K; i++) cin >> bv[i];

    // 보석은 무게, 가격 오름차순으로 정렬하고 가방은 무게 오름차순으로 정렬
    sort(jv.begin(), jv.end());
    sort(bv.begin(), bv.end());

    priority_queue<int> pq;
    int idx = 0;
    ll res = 0;
    for(int i=0; i<K; i++){
        int cur_bag = bv[i];
        
        // 현재 가방에서 넣을 수 있는 보석들을 골라내고 
        // 그 중 가장 가격이 큰 보석을 합한다.
        while(idx < jv.size() && jv[idx].first <= cur_bag){
            pq.push(jv[idx].second);
            idx++;
        }

        if(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
    }
    cout << res;
}