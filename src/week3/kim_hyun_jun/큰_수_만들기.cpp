// greedy
// 공통 문제: 큰 수 만들기

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string max_string = "";
string res = "";
int K = 0;

// 풀이 1: 재귀로 풀려고 함
// 재귀로 풀 경우 시간이 많이 걸리고 생각할 게 많아짐
// 먼저 최대한 단순하게 생각하는 힘 기르자

// 가장 큰 문자열을 저장하고 조합을 만들어서 생각할려고 함
// 하지만 자리수가 7개가 아닌 백만이여서 시간 초과...
bool compare(const string &sub){
    int size = sub.size();
    if(size > max_string.size()){
        if(max_string <= sub.substr(0, max_string.size())){
            max_string = sub;
            return false;
        }
        else return true;
    }
    else{
        if(max_string.substr(0, size) <= sub){
            max_string = sub;
            return false;
        }
        else return true;
    }
}

void combination(string str, string sub, int i, int k){
    //저장해놓은 가장 큰 문자열과 비교
    if(sub.size() && compare(sub)) return;

    //k도 다 쓰고 문자열에 다 도달하면 리턴
    if(i >= str.size() && k == K){
        res = max(sub, res);
        return;
    }
    else if(sub.size() + k >= str.size()) return;

    //재귀를 통해 모든 조합 검사
    if(k < K) combination(str, sub, i+1, k+1);
    sub += str[i];
    combination(str, sub, i+1, k);
}

string solution(string number, int k) {
    K = k;
    max_string = number[0];
    combination(number, "", 0, 0);
    return res;
}


// 풀이 2: 그리디하게 선형적으로 풀었더니
// 훨씬 빠르게 해결가능
string solution1(string number, int k){
    string ans = number;
    int ind = 0;

    while(ind != ans.size() && k != 0){
        cout << ans << endl;
        if(ans[ind] < ans[ind+1]){
            ans = ans.substr(0, ind) + ans.substr(ind+1);
            if(ind != 0) ind--;
            k -= 1;
        }
        else{
            ind++;
        }
    }
    if(k != 0) ans = ans.substr(0, ans.size()-k);
    return ans;
}

int main(){
    string a = "4177252841";
    int k = 4;
    cout << solution1(a, k);
    cout << res;
}