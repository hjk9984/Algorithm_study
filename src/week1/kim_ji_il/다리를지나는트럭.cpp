/*  # 1번 풀이 (통과)
- 문제 : [다리를지나는트럭]
- 접근 방식 : bridge 덱 과 trucks 큐를 만들고, 덱과 큐가 빌때까지 한 칸씩 가면서 answer++
- 시간 복잡도 :  
*/

#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;


void clocking(deque<pair<int,int>>& t) {
	for (size_t i = 0; i < t.size(); i++) {
		t[i].second++;
	}
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	queue<int> trucks;  // 트럭 큐
	deque<pair<int,int>> bridge;  // 다리 덱 ( 트럭 무게 , 다리 idx )

	int sum_weight = 0;

	for (auto& elem : truck_weights) {  
		trucks.push(elem);
	}

	while (!trucks.empty() || !bridge.empty()) {  // 트럭 큐도 비고 다리 덱도 빌때까지.

		
			if (trucks.empty()) { // 트럭 큐가 비었으면 다리에 남아 있는 트럭 처리하고 break;

				while ((bridge.front().second < bridge_length)) { // 트럭이 다리를 지나갈때까지
					clocking(bridge); // 다리에 있는 모든 트럭  idx + 1
					answer++;
				}
				bridge.pop_front();  // 맨 앞에 트럭 pop()
				continue;
			}

			if ((sum_weight + trucks.front() <= weight)) { // 다리 허용 무게보다 작을때 다리 덱에 push
				sum_weight += trucks.front();
				bridge.push_back({ trucks.front(),0 });
				trucks.pop();
				clocking(bridge);
				answer++;
			}
			else {  // 다리 허용 무게 초과 했을때
				clocking(bridge);
				answer++;
			}

			if (bridge.front().second >= bridge_length) {
				sum_weight -= bridge.front().first;
				bridge.pop_front();
			}
	}

	return answer + 1;
}