//silver 1
//https://www.acmicpc.net/problem/2002

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N;      //<=1000
vector<string> v;
unordered_map<string, int> m;
bool arr[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int ans = 0;
    string str;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> str;
        v.push_back(str);
        m[str] = i;
    }

    int i = 0;
    while(i < N){
        cin >> str;
        if(v[i] != str){
            arr[m[str]] = true;
        }
        else{
            while(true){
                i++;
                if(!arr[i]) break;
            }
        }

    }
    
    for(int i=0; i<N; i++){
        if(arr[i]) ans++;
    }
    cout << ans;
}