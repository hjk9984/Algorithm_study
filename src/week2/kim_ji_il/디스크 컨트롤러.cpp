/*  # 1번 풀이 (통과)
- 문제 : [디스크 컨트롤러]  
- 접근 방식 : 우선 순위큐를 사용하여 작업의 소요시간이 작은 순으로 하나씩 뽑아내면 되겠다고 생각이 듬.
           주의할 점은 한 작업이 끝날때까지 다음 작업의 요청이 도착하지 않는 case도 생각해줘야한다( line 38 )
- 시간 복잡도 : O(n^2) ?
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
		return a.second > b.second;
	}
};
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int size = jobs.size();
	std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, cmp> pq;

	int time = 0, delay = 0;
	int cnt = 0;
    
    std::sort(jobs.begin(),jobs.end());

	for (int i = 0; i < size;i++) { // 모든 작업이 실행될때까지

		
		while (cnt < size && jobs[cnt][0] <= time) {  
			pq.push({ jobs[cnt][0], jobs[cnt][1] }); 
			cnt++;
		}

		if (pq.empty()) { // 다음 작업이 아직 요청되지 않았을때
			time = jobs[cnt][0];  // time을 옮겨 들어가게끔.
			i--; // 작업 실행 안됐으니깐 i--
			continue;
		}

		delay = time - pq.top().first;
		answer += (delay + pq.top().second);
		time += pq.top().second;
		pq.pop();

	}


	return answer / size;
}