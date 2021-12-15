
/*  # 1번 풀이 (통과)
- 문제 : [완주하지 못한 선수]
- 접근 방식 : 
	문제 카테고리가 hash라 unordered_map을 사용하려고 생각하였으나,
	참여 선수가 최대 100,000 이니 삽입의 시간복잡도가 O(logn)인 set/map으로도 가능하다고 판단.
	또 굳이 map의 value 값을 이용할 필요가 없다고 생각해서 중복이 가능한 multiset을 사용.
- 시간 복잡도 : O(nlogn) ?
*/

#include <string>
#include <vector>
#include <set>
 
using namespace std;
 
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    multiset<string> m_set;
    for(int i=0;i<participant.size();i++){  // O(n)
        m_set.insert(participant[i]);       // O(logn)
    }
    
    // 완주한 사람들의 이름을 뺀다.
    for(size_t i =0;i<completion.size();i++){
        m_set.erase(m_set.find(completion[i]));
    }
    
    // 마지막에 m_set에 남은 한 사람이 완주하지 못한 사람.
    answer = *(m_set.begin());
    
    return answer;
}

/* 조심할 점.
 erase( const key_type& key) -> key와 같은 값 전부 지우고, 지운 elem 개수 리턴.
27 line ) 처음에 m_set.erase(completion[i]); 이렇게 key 값을 인자로 줬다가 중복된 이름이 한번에 지워졌다.
 하나씩 지울때는 iterator를 반환하는 find 함수로 먼저 itr 찾을 것.
 */




/*  # 2번 풀이 (통과)
- 접근 방식 : 
	multiset 보다 빠른 unordered_map을 사용
- 시간 복잡도 : O(n) 
*/

#include<string>
#include<vector>
#include<unordered_map>	
 
using namespace std;
 
string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> u_m;
 
	// 없는 key 값을 추가하면 int의 default 값인 0이 들어간다.
	for (auto& elem : participant) u_m[elem]++; 
 
	for (auto& elem : completion) u_m[elem]--;  // 완주자--
 
	// value 값이 1인 사람 = 완주 못한 사람.
	for (auto& elem : u_m) {
		if (elem.second > 0) {
			answer = elem.first;
			return answer;
		}
	}
}
