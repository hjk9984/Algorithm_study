//완전탐색
//https://programmers.co.kr/learn/courses/30/lessons/42839

//풀이 1 --> numbers를 모두 사용하는 순열을 사용하므로 오답
//      --> numbers의 일부분을 추출해서 소수인지 판단해야함
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//소수인지 확인하는 함수
bool isPrimeNumber(int num) {
    int flag = true;
    int i=2;
    while(i<num) {
        if(num % i == 0) {
            flag = false;
            break;
        }
        i++;
    }
    return flag;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> vec;
    
    sort(numbers.begin(), numbers.end());
    
    for(char c : numbers) {
        vec.push_back(atoi(&c)); 
    }
    
    do{
        string str = "";
		for(int i=0; i<vec.size(); i++){
            str += to_string(vec[i]);
		}
        if(isPrimeNumber(stoi(str)) == true) {
            answer++;
        }

	}while(next_permutation(vec.begin(),vec.end()));
    
    return answer;
}

//풀이 2
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//소수인지 확인하는 함수
bool isPrimeNumber(int num) {
    int flag = true;
    if (num == 0 || num == 1) {
        return false;
    }
    int i=2;
    while(i<num) {
        if(num % i == 0) {
            flag = false;
            break;
        }
        i++;
    }
    return flag;
}

int solution(string numbers) {
    unordered_set<int> set; //순열을 구하다보면 같은 숫자가 존재하므로 set에다가 소수인 숫자를 담아 중복 제거
    
    sort(numbers.begin(), numbers.end());
    do{
        int n;
		for(int i=1; i<numbers.size()+1; i++){
            //numbers로 조합할 수 있는 모든 숫자들
            n = stoi(numbers.substr(0,i));
            if(isPrimeNumber(n) == true) {
                set.insert(n);
            }    
		}
	}while(next_permutation(numbers.begin(),numbers.end()));
    
    return set.size();
}