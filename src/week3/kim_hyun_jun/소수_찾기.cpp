#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

#define num_size 100000001

int n;
bool arr[num_size] = {};
vector<string> v;

bool compare(const char &a, const char &b){
    return a > b;
}

void combination(int k, string str, const string &numbers){
    if(k == n){
        if(str.size() == 0) return;
        v.push_back(str);
    }
    else{
        str.push_back(numbers.at(k));
        combination(k+1, str, numbers);
        str.pop_back();
        combination(k+1, str, numbers);
    }
}

bool isPrime(int n) { 
    if (n < 2) return false; 
    // 에라토스테네스의 체 
    for (int i = 2; i <= sqrt(n); i++) 
        if (n % i == 0) return false; 
    return true; 
}


int solution(string numbers) {
    int answer = 0;
    n = numbers.size();
    vector<int> nums;

    sort(numbers.begin(), numbers.end());

    combination(0, "", numbers);

    for(auto e: v){
        do{
            nums.push_back(stoi(e));
        }while(next_permutation(e.begin(), e.end()));
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for(auto &e : nums){
        if(isPrime(e)){
            answer++;
        }
    }
    

    return answer;
}