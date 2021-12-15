/*  # 1번 풀이 (통과)
- 문제 : [기능개발]
- 접근 방식 : 작업 별로 남은 날 days를 구해주고, work_needs 큐에 있는 days와 비교하여 배포 할 수 있는 작업(cnt)의 수를 구해준다.
            마지막에 work_needs 큐에 남은 작업들은 마지막에 완료.
- 시간 복잡도 : O(nlogn)
*/

#include <string>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> work_needs;

	int max = 0;
	for (int i = 0; i < progresses.size(); i++) {
		int days;
		if ((100 - progresses[i]) % speeds[i]) {
			days = (100 - progresses[i]) / speeds[i] + 1;
		}
		else {
			days = (100 - progresses[i]) / speeds[i];
		}
		int cnt = 0;
		
		while (!work_needs.empty() && work_needs.front() < days) {
			cnt++;
			work_needs.pop();
		}
		if (cnt) answer.push_back(cnt);
		work_needs.push(days);
	}
	if (!work_needs.empty()) answer.push_back(work_needs.size());



	return answer;
}