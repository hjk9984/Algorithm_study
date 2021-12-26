/*  # 1번 풀이 (통과)
- 문제 : [소수 찾기]  
- 접근 방식 : 
    우선 순열을 구하고 구한 순열을 set에 집어 넣어 중복을 없애준다.
    set에서 하나씩 꺼내 소수를 판별하고 그 갯수를 카운트 해준다.
    아리토스테네스의 체와 permutation(순열)을 따로 함수로 만들어서 사용
- 시간 복잡도 :  
*/
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
 
using namespace std;
// 순열, 소수 구하기, set
 
std::set<int> ss;
vector<char> vec(8);
bool visited[8];
 
void permutation(int k, int r, int n, string numbers) {
	if (k == r) {
		string str = "";
		for (int i = 0; i < r; i++) {
			str += vec[i];
		}
		ss.insert(stoi(str));
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			vec[k] = numbers[i];
			visited[i] = true;
			permutation(k + 1, r, n, numbers);
			visited[i] = false;
		}
	}
}
bool is_prime(int num) {
	if (num < 2) return false;
	for (int i = 2; i <= std::sqrt(num); i++) {
		if (num%i == 0)return false;
	}
	return true;
}
 
int solution(string numbers) {
	int answer = 0;
	int size = numbers.length();
 
	// nP1, nP2 ... nPsize 의 모든 순열을 구해준다.
	for (int i = 1; i <= size; i++) {
		permutation(0, i, size, numbers);
		std::fill_n(vec.begin(), 8, NULL); // for 루프 돌때마다 전역 변수는 초기화
		std::fill_n(visited, 8, false);
	}
 
	for (auto& elem : ss) {
		if (is_prime(elem)) answer++;
	}
 
	return answer;
}