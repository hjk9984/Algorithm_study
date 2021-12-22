//https://programmers.co.kr/learn/courses/30/lessons/81301

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> str = {"zero", "one", "two", "three", "four", "five",
                            "six", "seven", "eight", "nine"};
    vector<string> num = {"0", "1", "2", "3", "4", "5",
                            "6", "7", "8", "9"};

    bool find = true;
    while(find == true) {
        for(int i=0; i<10; i++) {
            size_t nPos = s.find(str[i]);
            if(nPos != string::npos) {
	            s.replace(nPos, str[i].size(), num[i]);
                find = true;
                break;
            } else if(nPos == string::npos && i == 9) {
                find = false;
            }
        }
    }
    answer = stoi(s);

    return answer;
}