#include <queue>
#include <iostream>

using namespace std;

int main()
{
    int answer = 0;
	int n, m;
    priority_queue<int, vector<int>, greater<int> > pq; //min heap

	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> m;
        pq.push(m);
	}

    while(pq.size() > 1) {
        //가장 작은 카드 묶음 2개를 꺼낸다.
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        answer += a + b;
        //합친 2개의 카드 묶음을 더해서 다시 큐에 넣는다.
        pq.push(a + b);
    }

	cout << answer << "\n";

	return 0;
}