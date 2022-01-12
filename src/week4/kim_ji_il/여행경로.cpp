/*
- 문제 : [여행경로]  
- 접근 방식 : 
    stack 을 이용해서 dfs 해줬고, visited 배열을 따로 사용하지 않고 2차원 벡터 tickets 를 하나씩 없애주는걸로 방문을 체크했다.
- 시간 복잡도 : 
*/
#include <string>
#include <vector>
#include<algorithm>
#include<stack>

using namespace std;

string current;
stack<string> st;
bool flag = true;

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	
	// 몰랐는데, sorting을 할때, 첫번째 값이 같으면 다음 원소를 비교해서 정렬해준다.
	std::sort(tickets.begin(), tickets.end());
	
	st.push("ICN");
	

	while (tickets.size()) {
		flag = true;
		current = st.top();
		
		size_t i;
		for (i = 0; i < tickets.size(); i++) {
			if (tickets[i][0] == current) {
				st.push(tickets[i][1]);
				tickets.erase(tickets.begin() + i);
				flag = false;
				break;
			}
		}
		//if (i == tickets.size() && flag) {  // 고립된 노드로 들어갔거나, size()가 줄어들어 i랑 똑같아 지거나.
		//	answer.push_back(st.top());
		//	st.pop();

		//}
	}
	while (!st.empty()) {
		answer.push_back(st.top());
		st.pop();
	}
		
	std::reverse(answer.begin(), answer.end());

	return answer;
}