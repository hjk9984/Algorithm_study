#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 11

using namespace std;

bool setUsed[MAX];
bool permUsed[MAX];
string S;
vector<int> answer;

int string_to_int(string numbers) {
    
    int i = 0;
    int ret = 0;
    while ( numbers[i] != '\0') {
        ret *= 10;
        ret += numbers[i] - 48;
        i++;
    }
    return (ret);
}

void permutation(int k, int size, string number) {
    if (number.length() == 1) {
        answer.push_back(string_to_int(number));
        return ;
    }

    if (k == size) {
        answer.push_back(string_to_int(S));
        return ;
    }
    for(int i = 0; i < number.length(); i++){
        if (permUsed[i] == true) continue;
        permUsed[i] = true;
        S.push_back(number[i]);
        permutation(k + 1, size, number);
        S.pop_back();
        permUsed[i] = false;
    }
}

void power_set(int k, int size, string numbers) {

    if (k == size) {
        string P = "";
        for(int i = 0; i < size; i++) {
            if (setUsed[i] == true) {
                P.push_back(numbers[i]);
            }
        }
        if (P.size() > 0) {
            permutation(0, P.size(), P);
        }
        return ;
    }
    // tree 왼쪽(P 포함 X)
    setUsed[k] = false;
    power_set(k + 1, size, numbers);
    // tree 오른쪽(P 포함 O)
    setUsed[k] = true;
    power_set(k + 1, size, numbers);
}

bool is_prime_number(int num) {
    if (num < 2) {return false;}

    for(int i = 2; i*i <= num; i++) {
        if (num % i == 0) return false; 
    }
    return true;
}

int solution(string numbers) {
    int result = 0;

    int size = numbers.length();

    power_set(0,size,numbers);
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    for(int i = 0; i < answer.size(); i++) {
        if (is_prime_number(answer[i]))
            result++;
    }
    return result;
}
