/*  # 1번 풀이 (통과)
- 문제 : [모의고사]  
- 접근 방식 : 
    어렵지 않았던 문제. 1,2,3 수포자 패턴을 입력으로 들어오는 answers와 비교하면서 정답 횟수 카운트.    
- 시간 복잡도 : O(n) ?
*/
#include <vector>
#include <string>
#include<algorithm>
 
using namespace std;
 
int first[] = { 1,2,3,4,5 };
int second[] = { 2,1,2,3,2,4,2,5 };
int third[] = { 3,3,1,1,2,2,4,4,5,5 };
 
int f_cnt, s_cnt, t_cnt; // 수포자 1,2,3이 맞힌 횟수.
 
vector<int> solution(vector<int> answers) {
	vector<int> answer;
 
	int f_length = sizeof(first) / sizeof(first[0]);
	int s_length = sizeof(second) / sizeof(second[0]);
	int t_length = sizeof(third) / sizeof(third[0]);
 
	for (size_t i = 0; i < answers.size(); i++) {
		int correct = answers[i];
 
		if (first[i%f_length] == correct) f_cnt++;
		if (second[i%s_length] == correct) s_cnt++;
		if (third[i%t_length] == correct) t_cnt++;
 
	}
	vector<int> temp(3);
	temp[0] = f_cnt;
	temp[1] = s_cnt;
	temp[2] = t_cnt;
    
    // 가장 높은 값이 두 개 이상일때를 따로 처리해줬으나 이렇게 하지 않아도 된다는것을 알았다.
	if (count(temp.begin(), temp.end(), *max_element(temp.begin(), temp.end())) >= 2) {
		int max = *max_element(temp.begin(), temp.end());
        for(int i=0;i<3;i++){
            if (max == temp[i]) answer.push_back(i+1);
        }
	}
	else {
		answer.push_back(max_element(temp.begin(), temp.end()) - temp.begin() + 1);
	}
	
	return answer;
}