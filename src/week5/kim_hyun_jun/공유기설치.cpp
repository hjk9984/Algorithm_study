//https://www.acmicpc.net/problem/2110

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C, tmp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;

    cin >> N >> C;
    for(int i=0; i<N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int l = v[0];
    int r = v[N-1];
    int m = (l+r)/2;    //가장 인접한 공유기의 거리

    while(r - l > 1){
        int prev = v[0];
        int cur = 0;
        int installed = 1;
        for(int i=1; i<N; i++){
            cur += v[i] - prev;
            prev = v[i];
            if(cur >= m){
                cur = 0;
                installed++;
            }
        }

        if(installed < C)
            r = m;
        else
            l = m;
        m = (l+r)/2;
    }

    cout << m;
}