/*  # 1번 풀이 (통과)
- 문제 : [요세푸스]  https://www.acmicpc.net/problem/1158
- 접근 방식 : 유명한 요세푸스 문제, 처음 보고는 어떻게 풀지 감이 잡히지 않았지만, 컨셉만 알면 구현은 어렵지 않았던 문제.
            1.queue를 이용하거나, 2.Ciurcular Linked List or 3.Recursion으로 풀이 가능.
*/
#include<iostream>
#include<queue>
 
using std::cout; using std::cin;
 
int n, k;
 
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
 
	cin >> n >> k;
	
	std::queue<int> que;
    
	for (int i = 1; i <= n; i++) {
		que.push(i);
	}
    
	cout << "<";
	while (!que.empty()) {
		for (int i = 0; i < k-1; i++) {
			int cur = que.front();
			que.pop();
			que.push(cur);
		}
		if (que.size() == 1) cout << que.front();
		else { cout << que.front() << ", " ; }
		que.pop();
	}
	cout << ">";
	
	return 0;
}