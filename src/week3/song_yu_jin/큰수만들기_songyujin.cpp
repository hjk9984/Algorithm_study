//탐욕법
//https://programmers.co.kr/learn/courses/30/lessons/42883

//풀이 1 --> 순열, 조합으로 풀려고 하니까 시간 초과 및 오답
//      --> 1234, k=2 에서 42 는 경우의 수에 포함 안되므로 하기 풀이 방법 잘못됨
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<int> temp(number.length());
    //k개의 수를 제거 -> number에서 (number의 자리수 - k개) 로 만들 수 있는 가장 큰 값 구하기
    int size = number.length() - k;
    //조합 이용
    for(int i=0; i<size; i++) {
        temp[i] = 1;
    }
    int max = 0;
    do {
        string str = "";
        for(int i=0; i<number.length(); i++) {
            if(temp[i] == 1) {
                str += number[i];
            }
        }
        cout << str << endl;
        if(stoi(str) >= max) {
            max = stoi(str);
        }
        
    }while(prev_permutation(temp.begin(), temp.end()));
    
    answer = to_string(max);
    
    return answer;
}

//풀이 2
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int length = number.length() - k; //최종 답 자리수
    int index = 0;
    for(int i=0; i<length; i++) {
        char max = number[index];
        for(int j=index; j<=k+i; j++) {
            if(max < number[j]) {
                max = number[j];
                index = j;
            }
        }
        answer += max;
        index++;
    }
    return answer;
}