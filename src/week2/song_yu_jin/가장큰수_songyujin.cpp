//정렬
//https://programmers.co.kr/learn/courses/30/lessons/42746


//풀이방법 1: next_permutation 순열 이용
//numbers 원소들의 모든 경우의 수를 구하면 될 것 같아서 순열 이용하려 했지만 시간 초과남
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    vector<string> vector;
    do{
        string s = "";
		for(int i=0; i<numbers.size(); i++){
            s += to_string(numbers[i]);	
		}
		vector.push_back(s);

	}while(next_permutation(numbers.begin(),numbers.end()));
    
    sort(vector.begin(), vector.end());

    return vector[vector.size()-1];
}
    
//풀이방법 2: 비교 함수 이용한 정렬하기
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    return a+b > b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    //number 원소들을 각각 비교할 때 int 로 비교 못하므로 형 변환 필요
    for(int i=0; i<numbers.size(); i++) {
        str.push_back(to_string(numbers[i]));
    }
    sort(str.begin(), str.end(), compare);
    
    for(int i=0; i<str.size(); i++) {
        answer += str[i];
    }
    
    if(str[0] == "0") {
        answer = "0";
    }
    return answer;
}