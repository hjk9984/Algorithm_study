/*  # 1번 풀이 (통과)
- 문제 : [카드 정렬하기]  
- 접근 방식 : 우선 정렬하고 앞에서부터 하나씩 더해 나가면 될 거라고 판단해서 그대로 구현했다가 틀렸다.
            30 40 50 60 이 반례.  결국 원소를 집어넣을때 정렬을 유지하게끔 우선 순위 큐를 사용하여 해결했다.
- 시간 복잡도 : O(nlogn) ?
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
 
 
using std::cout; using std::cin;
using std::vector;
 
int N;
std::priority_queue<int,vector<int>,std::greater<int>> pq;
 
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
 
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	int answer = 0;
 
	
	while (pq.size() != 1) {
 
		int x = pq.top();  // 첫번째
		pq.pop();
 
		int y = pq.top();  // 두번째
		pq.pop();
 
		answer += (x + y);
		pq.push(x + y);
	}
	
	cout << answer;
	
	return 0;
}