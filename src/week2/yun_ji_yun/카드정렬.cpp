#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 100000
/* 확인용
void print_vec(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
*/

int main() {
    int N;
    cin >> N;
    int b[N];
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    int size = sizeof(b) / sizeof(b[0]);
    vector<int> num_of_bundle(b, b + size);
    
    /* 필요한줄 알았는데 없다
    sort(num_of_bundle.begin(), num_of_bundle.end()); */

    priority_queue<int, vector<int> ,greater<int> > pq;
    for(int i = 0; i < num_of_bundle.size(); i++) {
        pq.push(num_of_bundle[i]);
    }
    // print_vec(num_of_bundle);

    vector<int> combines;
    while (pq.size() != 1) {
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        combines.push_back(min1 + min2);
        // if (pq.empty()) break;
        
        pq.push(min1 + min2);
    }
    // print_vec(combines);
    int answer = 0;
    for(int i = 0; i < combines.size(); i++) {
        answer += combines[i];
    }

    cout << answer << "\n";
}