//https://www.acmicpc.net/problem/5557

#include <iostream>
#include <vector>
#include <map>
#define ll unsigned long long
using namespace std;

// 재귀함수로 풀면 되겠다.

// 8 3 2 6
// 8 
//   11, 5
//     13, 13, 13, 13,  9, 7, 3 >> 중복되는 숫자들이 많아짐
// 해쉬테이블 >> 메모라이제이션에 사용함
// map<int, int> m;  m[13] = 4

map<int, ll> m;
ll arr[105];
ll ans, N, res = 0;

void solution(){
    // 8 3 2 6
    // 8 3 2 4 8 7 2 4 0 8 8

    // m[8] = 1;
    int idx = 1;

    while(idx < N-1){
        ll new_arr[22] = {};

        for(int i=0; i<=20; i++){
            if(m[i] == 0) continue;
            if(i + arr[idx] >= 0 && i + arr[idx] <= 20) new_arr[i+arr[idx]] += m[i]; // m[11] = 1;
            if(i - arr[idx] >= 0 && i - arr[idx] <= 20) new_arr[i-arr[idx]] += m[i]; // m[5] = 1;
        }

        for(int i=0; i<=20; i++) m[i] = new_arr[i];
        
        idx++;
    }

    res = m[ans];
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i<N-1; i++) cin >> arr[i];
    cin >> ans;

    // 8 3 2 6
    //m[8] = 1;
    // m[11] = 1, m[5] = 1;
    m[arr[0]] = 1;
    solution();

    cout << res;
}