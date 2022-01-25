#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

ll res = 0;
vector<int> v;

void binary_search(ll a, ll b, int n){
    if(b - a <= 1){
        res = b;
        return;
    }
    ll mid = (a+b) / 2;
    ll cnt = 0;
    for(auto &e : v) cnt += mid / e;

    if(cnt >= n) binary_search(a, mid, n);
    else if(cnt < n) binary_search(mid, b, n);
}

long long solution(int n, vector<int> times) {
    // n, time <= 10억
    sort(times.begin(), times.end());
    ll a = 0;
    ll b = times[0] * (long long)n;

    for(auto e : times) v.push_back(e);

    binary_search(a, b, n);

    return res;
}