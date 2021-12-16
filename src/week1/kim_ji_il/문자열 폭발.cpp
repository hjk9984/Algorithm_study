/*  # 1번 풀이 (시간 초과)
- 문제 : [문자열 폭발]  https://www.acmicpc.net/problem/9935
- 접근 방식 : 
	문자열 조작으로 풀 수 있다고 생각하여 풀어봤는데 시간초과.
	폭탄을 만나면 그 전 문자까지 저장하기.  이 과정을 더 이상 폭탄을 찾지 못할때까지 진행.
- 시간 복잡도 : ??
*/

#include<iostream>	
#include<vector>
#include<string>

using std::cout; using std::cin;
using std::vector; using std::string;

int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string str, bomb;
	cin >> str;
	cin >> bomb;

	string answer = "";

	bool is_in = false;
	bool flag = false;

	size_t previous = 0;
	size_t current = str.find(bomb);

	while (current != string::npos) {
		is_in = true;
		string substring = "";
		if (!flag) {
			substring = str.substr(previous, current - previous);
		}
		else {
			substring = answer.substr(previous, current - previous);
		}
		answer += substring;

		if (answer.find(bomb, 0) != string::npos) break;

		if (str.length()-1 <= current + bomb.length()) {
			substring = str.substr(current+bomb.length()); // 문자열 끝까지
			answer += substring;
			current = answer.find(bomb, previous);
			flag = true;
			previous = 0;
		}

		if(!flag){
			previous = current + bomb.length();
			current = str.find(bomb, previous);
		}
		
	}

	is_in ? cout << answer : cout << "FRULA";


	return 0;
}

/*  # 2번 풀이 (시간 초과)
- 문제 : [문자열 폭발]  https://www.acmicpc.net/problem/9935
- 접근 방식 : 
	문자열 조작으로 풀 수 있다고 생각하여 풀어봤는데 시간초과.
	폭탄을 만나면 그 전 문자까지 저장하기.  이 과정을 더 이상 폭탄을 찾지 못할때까지 진행.
- 시간 복잡도 : 
- 알게 된 점 : substr(pos,count) ->  pos가 str 인덱스 범위를 넘을때는 런타임 오류 발생해야하는데 VS는 예외처리가 되어 있는지 발생 안시킨다.
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<deque>
 
using std::cout; using std::cin;
using std::vector; using std::string;
 
string str, bomb;
std::stack<char> st;
 
 
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
 
	cin >> str >> bomb;
	
	int cnt = 0;
	for (int i = 0,j=0; i < str.length();i++) {
		st.push(str[i]);
		if (str[i] == bomb.back() && st.size() >= bomb.size()) {
			string temp ="";
			for (int i = 0; i < bomb.size(); i++) {
				temp += st.top();
				st.pop();
			}
 
			std::reverse(temp.begin(), temp.end());
 
			if (bomb != temp) {
				for (auto& elem : temp) {
					st.push(elem);
				}
			}
		}
 
	}
	if (st.empty()) {
		cout << "FRULA";
		return 0;
	}
	std::deque<char> answer;  // 남은 스택 값을 출력하려고 덱 만들었는데 reverse로 해도 된다.
	while (!st.empty()) {  
		answer.push_front(st.top());
		st.pop();
	}
 
	for (auto& elem : answer) {
		cout << elem;
	}
	return 0;
}