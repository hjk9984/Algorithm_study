// 공통 문제: 완탐, 그리디
// 조이스틱

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

string ans;
int global_cnt = 987654321;
bool used[20][7654321] = {};

// 풀이1: 완탐으로 각 조이스틱의 움직임을 구현함
// 시간초과가 5번 케이스에서만 걸림

void go(string str, int cnt, int i, int chk){
    if(cnt >= global_cnt) return;
    if(used[i][chk]) return;
    if(str == ans){
        global_cnt = cnt;
        return;
    }

    used[i][chk] = true;

    //cout << str << " " << i << endl;
    // 알파벳 맞추기
    if(str[i] != ans[i]){
        int n = ans[i] - str[i];
        int reverse_n = 'Z' - ans[i] + 1;
        int res = min(n, reverse_n);
        int b_chk = 1 << i;
        
        char tmp = str[i];
        str[i] = ans[i];
        go(str, cnt+res, i, chk | b_chk);
        str[i] = tmp;
    }

    // 커서 이동
    if(i == ans.size()-1) go(str, cnt+1, 0, chk);
    else go(str, cnt+1, i+1, chk);

    if(i == 0) go(str, cnt+1, ans.size()-1, chk);
    else go(str, cnt+1, i-1, chk);
    used[i][chk] = false;
}


// 풀이 2: 결국 bfs로 풀었다
// bfs를 통해서 맞춘 알파벳들의 인덱스를 비트로 표현하여
// 2차원 used 배열을 사용함
// 맞춘 조합별로 방문을 확인하고 이미 방문을 했다면 무시하는 방식으로 짬
struct sub_str {
    string str;
    int cnt, i, chk;
};

void bfs(string init){
    queue<sub_str> q;
    q.push({init, 0, 0, 0});
    used[0][0] = true;

    while(!q.empty()){
        string str = q.front().str;
        int cnt = q.front().cnt;
        int i = q.front().i;
        int chk = q.front().chk;
        q.pop();

        if(cnt >= global_cnt) continue;
        if(str == ans){
            global_cnt = cnt;
            continue;
        }

        //알파벳 맞추기
        if(str[i] != ans[i]){
            int b_chk = 1 << i;
            if(!used[i][chk | b_chk]){
                int n = ans[i] - str[i];
                int reverse_n = 'Z' - ans[i] + 1;
                int res = min(n, reverse_n);
                
                char tmp = str[i];
                str[i] = ans[i];
                used[i][chk|b_chk] = true;
                q.push({str, cnt+res, i, chk | b_chk});
                str[i] = tmp;
            }
        }

        //커서 이동
        if(i == ans.size()-1 && !used[0][chk]){
            used[0][chk] = true;
            q.push({str, cnt+1, 0, chk});
        }
        else if(i != ans.size()-1 && !used[i+1][chk]){
            used[i+1][chk] = true;
            q.push({str, cnt+1, i+1, chk});
        }

        if(i == 0 && !used[ans.size()-1][chk]){
            int size = ans.size() - 1;
            used[size][chk] = true;
            q.push({str, cnt+1, size, chk});
        }
        else if(i != 0 && !used[i-1][chk]){
            used[i-1][chk] = true;
            q.push({str, cnt+1, i-1, chk});
        }
    }
}

int solution(string name) {
    ans = name;
    string init = "";
    for(int i=0; i<name.size(); i++)
        init += "A";
    bfs(init);

    return global_cnt;
}

int main(){
    string tmp = "JEROEN";
    cout << solution(tmp);
}