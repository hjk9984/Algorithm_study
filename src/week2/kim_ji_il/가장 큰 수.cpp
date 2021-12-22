/*  # 1번 풀이 (통과)
- 문제 : [가장 큰 수]  
- 접근 방식 : 
    문자열을 사전 순으로 정렬하는데, 글자 수가 같을 때와 다를 때 정렬 순서를 custom 해줬다.
    cmp 함수를 만들때 한번에 만들지 못하고 다른 사람의 코드를 참조하였다. ( a+b 와 b+a를 비교해서 사전 순으로 먼저 오는게 큰 수이다.)
	모든 문자가 0 일떄는 "000..00" 이 아니라 0 을 리턴해야한다.
- 시간 복잡도 : O(nlogn) 
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& a,string& b){
    if(a.length() == b.length()){
        return a>b;
    }else { // 비교하는 숫자 글자수가 다르다면
        return a+b > b+a;
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for(auto& elem:numbers) temp.push_back(to_string(elem));
    
    std::sort(temp.begin(),temp.end(),cmp);

    if(temp[0]=="0"){
        return "0";
    }

    for(auto& elem:temp) answer +=elem;
    
    return answer;
}