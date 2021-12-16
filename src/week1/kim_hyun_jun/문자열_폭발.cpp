//gold 4
//https://www.acmicpc.net/problem/9935

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str, boom;
    vector<char> v;
    cin >> str >> boom;

    int bs = boom.size();
    for(int i=0; i<str.size(); i++){
        v.push_back(str[i]);
        if(v.size() >= bs){
            bool is_boom = true;
            for(int j=v.size()-bs, k=0; j<v.size(); j++, k++){
                //이 부분을 그냥 다른 함수로 짰으면 깔끔했을 듯
                if(v[j] != boom[k]){
                    is_boom = false;
                    break;
                }
            }
            if(is_boom){
                //다시 뱉는 게 아닌 v의 다음 넣을 인덱스 설정
                for(int j=0; j<bs; j++) v.pop_back();
            }
        }
    }

    if(!v.empty()){
        for(auto e: v) cout << e;
    }
    else cout << "FRULA";
}

//char배열을 사용하려면
//char stack[10];
//stack[끝 인덱스] = '\0'
//cout << stack << endl;


//다른 사람 풀이
// int len, bomblen;
// char arr[1000005];
// char bomb[40];
// char ans[1000005];

// int check(int pos) {
//     for (int i = pos; i < pos + bomblen; i++) {
//         if (ans[i] != bomb[i - pos]) { return 0; }
//     }
//     return 1; //폭발 문자열 발견
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
    
//     cin >> arr >> bomb;
//     len = strlen(arr);
//     bomblen = strlen(bomb);
//     int cur = 0;
//     for (int i = 0; i < len; i++) {
//         ans[cur] = arr[i];
//         cur++;
//         if (cur - bomblen >= 0 && check(cur - bomblen)) {
//             cur -= bomblen;
//         }
//     }
//     ans[cur] = 0;       //이렇게도 자를 수 있다.
//     if (cur == 0) { cout << "FRULA\n"; }
//     else { cout << ans << "\n"; }


//     return 0;
// }