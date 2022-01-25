#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    
    int l = 1;
    int r = distance;
    int m = (r-l)/2;

    while(r - l > 1){
        int removed = 0;
        int cur = 0;
        int prev = 0;
        for(auto e : rocks){
            cur += e - prev;
            prev = e;
            if(cur < m) 
                removed++;
            else 
                cur = 0;
        }

        if(removed > n)
            r = m;
        else
            l = m;
        m = (l + r) / 2;
    }

    return l;
}