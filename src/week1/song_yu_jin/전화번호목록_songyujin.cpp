//해시
//https://programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; i++) {
        //정렬을 먼저 했으므로 phone_book[i] < phone_book[i+1] 항상 크기 때문에 이중 포문 불필요
        //string substr (size_t pos = 0, size_t len = npos)
        if (phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()))
            return false;
    }
    
    return answer;
}

