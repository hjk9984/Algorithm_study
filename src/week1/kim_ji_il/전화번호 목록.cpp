
/*  # 1번 풀이( 정확성 테스트 통과 / 효율성 테스트 실패)
- 문제 : [전화번호 목록] https://programmers.co.kr/learn/courses/30/lessons/42577
- 접근 방식 :
	처음에는 phone_book을 unordered_set에 넣고,
    unordered_set에서 전화번호 길이 순서대로 하나씩 꺼내서 나머지랑 비교하는 방법으로 풀려고 했으나,
    unordered_set 은 원소의 순서를 보장해주지 않으니,
    phone_book (vector)를 문자열 길이 순서로 정렬하고 앞에서부터 unordered_set 이랑 비교 하는 방법으로 접근.
- 시간 복잡도 : O(n^2) ?
- 알게 된점 : std::string의 substr 함수는 O(n)의 시간복잡도를 가짐.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
 
using namespace std;
 
 
bool cmp(const string& a,const string& b) { // 문자 길이 오름차순 정렬.
	return a.length() < b.length();
}
bool solution(vector<string> phone_book) {
	unordered_set<string> hash_set;

    for (auto& elem : phone_book)  hash_set.insert(elem);
 
	sort(phone_book.begin(), phone_book.end(), cmp);
 
	
	for (int i = 0; i < phone_book.size(); i++) {
		int size = phone_book[i].length();
        
		hash_set.erase(hash_set.find(phone_book[i]));  // 비교할 문자를 hash_set에서 삭제.
		
        // hash_set에 있는 나머지 문자들과 비교.
		for (unordered_set<string>::iterator itr = hash_set.begin(); itr != hash_set.end();itr++) {
			if(size > (*itr).length()) continue;  // 시간 복잡도 줄이고자.
 
			if (phone_book[i] == (*itr).substr(0, size)) return false;
						
		}
	}
	return true;
}


/*  # 2번 풀이( 통과 )
- 접근 방식 :
	1번 풀이에서 시간 초과 없애보려고 했지만, 실패하고 다른 사람 코드 참고하여 2번 풀이 진행.
    phone_book 벡터를 문자열을 길이가 긴 순서대로 내림차순 하여 긴 문자부터 탐색.
- 시간 복잡도 : O(nlogn) ?
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
 
using namespace std;
 
 
bool cmp(const string& a,const string& b) {  // 문자 길이가 긴거부터 내림차순.
	return a.length() > b.length();
}
 
bool solution(vector<string> phone_book) {
	//bool answer = true;
	unordered_set<string> hash_set;
    
    for (auto& elem : phone_book)  hash_set.insert(elem);
 
	sort(phone_book.begin(), phone_book.end(),cmp);  // O(nlogn)
	
	for (int i = 0; i < phone_book.size(); i++) {
        string str = "";
        
        // 중복 문자는 없으니 i번째 phone_book.size() -1 까지랑 비교하면 된다. 
        for(int j=0;j<phone_book[i].size()-1;j++){ 
            str += phone_book[i][j];
            if(hash_set.find(str) != hash_set.end()) return false;
        }
	}
 
	return true;
}