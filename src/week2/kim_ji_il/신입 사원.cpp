/*  # 1번 풀이 (통과)
- 문제 : [신입 사원]  
- 접근 방식 : 
        pair<int,int> 를 정렬하고 배열의 첫번째 second 값을 기준으로 순회하면서 비교 값이 더 작으면 cnt++, 기준을 작은 값으로 재설정.
- 시간 복잡도 : O(nlogn) ?
*/
#include <iostream>
#include<vector>
#include<algorithm>
 
using std::cout; using std::cin;
using std::vector;
 
int T, N;
int cnt;
vector<std::pair<int, int>> score;
 
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
 
	cin >> T;
	while (T--) {
		cin >> N;
		score.reserve(N);
		int num = N;
		while (num--) {
			int x, y;
			cin >> x >> y;
			score.push_back({ x,y });
		}
		std::sort(score.begin(), score.end());
 
		int pivot_y = score[0].second;
 
		int cnt = 1;
		for (int i = 1; i < N; i++) {
			if(pivot_y > score[i].second) {
				pivot_y = score[i].second;
				cnt++;
			}
		}
 
		cout << cnt << '\n';
		score.clear();
	}
	return 0;
}