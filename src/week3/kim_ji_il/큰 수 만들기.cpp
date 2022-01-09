/*  # 1번 풀이 (통과)
- 문제 : [큰 수 만들기]  
- 접근 방식 : 
    그리디 문제였는데 그리디라는걸 아는것보다 구현의 비중이 높았던 문제.
    나는 string을 int로 바꿔서 max_element로 대소 비교를 해줬는데, char 끼리 비교해도 동일한 대소 비교 결과가 나오기 때문에 굳이 int로 변환할 필요가 없었다.
    테스트 케이스 12만 통과 못하길래 힌트로 반례를 검색해보았다. 
- 시간 복잡도 :  
*/
#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;


string solution(string number, int k) {
	string answer = "";

	int i = 0;
	while (k) {
		int start = i;
		vector<int> temp;
		for (i; i <= start+k; i++) {
			temp.push_back(number[i] - '0');
		}
		vector<int>::iterator temp_itr = max_element(temp.begin(), temp.end());

		i = start + (temp_itr - temp.begin()) + 1; // 가장 큰 수 다음 수를 i로
		k -= temp_itr - temp.begin(); // 선택한수랑 시작한수 거리만큼 제거한거다.
		answer += to_string(*temp_itr);

		if (number.length() - i <= k) return answer;  // 이거 안하면 테스트케이스 12번 통과 X   ("1111",2) 일때 통과하게끔. 버려야되는 문자랑 남은 문자랑 같아질 때 리턴.
	}
	for (int j = i; j < number.length(); j++) { // k가 0이라서 빠져나왔는데 number에 나머지 문자들 있을때. ( "4177252841",4)
		answer += number[j];
	}


	return answer;
}

/*  # 2번 풀이 - 다른 분 풀인데 참신해서 공유.
- 문제 : [큰 수 만들기]  
- 접근 방식 : 
    student 벡터 하나 만들어서 체육복 개수를 나타내고 첫번째 학생부터 순회하면서 앞뒤로 체육복 빌릴 수 있으면 빌리고 answer++
    첫번째와 마지막 학생은 뒤나 앞을 비교 할 수 없기 때문에 동일한 로직을 했을때 out of range 오류가 날 수 있기 때문에 따로 처리.
- 시간 복잡도 :  
*/