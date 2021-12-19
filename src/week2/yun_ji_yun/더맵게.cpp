#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // 프로그래머스 환경을 위한 전처리
    int arr_scoville[] = {1, 1};
    int s = sizeof(arr_scoville) / sizeof(arr_scoville[0]);
    vector<int> scoville(arr_scoville, arr_scoville + s);
    int K = 7;

    priority_queue<int, vector<int>, greater<int> > pq;
    
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    int cnt = 0;
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        if (first >= K) break;
        int second = pq.top();
        pq.pop();

        pq.push(first + second * 2);
        cnt++;
    }
    if (pq.size() == 1 && pq.top() < K) {
        cout << "-1" << endl;
        return 0;
    }
    cout << cnt << endl;
}

