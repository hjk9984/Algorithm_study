/*  # 1번 풀이 (통과)
- 문제 : [이중우선순위큐]  
- 접근 방식 : 
	큐를 덱처럼 사용할 수 없기에 ( 문제를 푼 뒤 다른사람의 보니 덱 처럼 사용하여 푼 코드도 있었음.) 우선순위 큐를 2개 사용해야겠다고 판단.
    stringstream 을 이용하여 입력을 받고 operations 명령어에 따라서 해당 명령어를 구현. 큐의 원소가 실제 원소개수랑 일치하지 않을 수 있기 때문에
     cnt가 0일때 모든 원소 비워줌으로서 큐의 개수 동기화.
- 시간 복잡도 : 
*/

#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	std::priority_queue<int> max_heap;
	std::priority_queue<int,vector<int>,std::greater<int>> min_heap;

	std::stringstream ss;
	string order;
	int number;
	int cnt = 0;

	for (size_t i = 0; i < operations.size(); i++) {
		
		ss.clear();
		ss.str(operations[i]);
		ss >> order >> number;

		if (cnt == 0) {  // 어느 한 큐가 비었으면 모두 비우게끔.
			while (!min_heap.empty()) min_heap.pop();
			while (!max_heap.empty()) max_heap.pop();
		}


		if (order == "I") {
			max_heap.push(number);
			min_heap.push(number);
			cnt++;
		}
		else { // D 일때
			if (cnt == 0) {  // 문제 제한사항에 의해 빈 큐에 대한 연산은 무시.
				continue;
			}
			if (number > 0) {
				max_heap.pop();
				cnt--;
			}
			else {
				min_heap.pop();
				cnt--;
			}
		}
	}

	if (!cnt) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		int max = max_heap.top();
		int min = min_heap.top();
		answer.push_back(max);
		answer.push_back(min);
	}

	return answer;
}