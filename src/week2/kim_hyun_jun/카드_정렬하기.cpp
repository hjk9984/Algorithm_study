// gold 4
// 카드 정렬하기
// https://www.acmicpc.net/problem/1715

//하나라도 떨어지면 선발 x
//return 선발할 수 있는 신입사원의 최대 인원 수

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> pq;
	int n;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		pq.push(-n);
	}

	int sum = 0;
	while (pq.size() != 1) {
		int n1 = -pq.top(); pq.pop();
		int n2 = -pq.top(); pq.pop();
		sum += n1 + n2;
		pq.push(-(n1 + n2));
	}

	cout << sum;
}