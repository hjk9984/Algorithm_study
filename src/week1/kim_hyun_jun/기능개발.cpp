//스택, 큐
//공통 문제: 기능개발

// return 각 배포마다 몇 개의 기능이 배포되는지
// #progress <= 100
// 배포는 하루에 한번, 하루의 끝에 이루어짐

#include <string>
#include <vector>
#include <queue>
using namespace std;

//풀이 1: 먼저 벡터로 풀어봤다.
//하루 지나고 진도를 업데이트하는 방식도 있지만 그러면 매일 계산해야하므로
//한번 배포까지의 일 수를 계산해서 곱해서 매일 계산 안하도록 함
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ans;
    int idx = 0;

    // O(n)
    while(idx < speeds.size()){
        // 배포까지의 날짜 수를 계산하기 위해서 100까지의 남은 진도를
        // speed로 나누고 나머지가 있으면 1을 더함
        // 이 과정을 깔끔하게 하는 방법이 있는 데 기억이 안 났다.
        int res = 100 - progresses[idx];
        int days = (res % speeds[idx] > 0) ? (res / speeds[idx]) + 1 : (res / speeds[idx]);

        bool meat_non_completion = false;
        int count = 0;
        for(int i=idx; i<speeds.size();i++){
            progresses[i] += days * speeds[i];
            if(progresses[i] >= 100){
                if(!meat_non_completion){
                    idx++;
                    count++;
                }
            }
            else
                meat_non_completion = true;
        }

        ans.push_back(count);
    }
    return ans;
}

//풀이 2: queue를 이용함
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ans;
    //queue<int> pro(progresses); 큐가 아니라서 초기화 못함
    queue<int> pro, sp;
    for(int i=0; i<speeds.size(); i++){
        pro.push(progresses[i]);
        sp.push(speeds[i]);
    }

    // O(n)
    int total_days = 0;
    while(!pro.empty()){
        //아래처럼 구현해서 맞추는 데 오래 걸림
        //배포가 끝나고 다음 작업을 처음으로 받으면 안 됐는 데
        //이를 체크를 했어야 했다.
        // int p = pro.front()
        int p = pro.front() + sp.front()*total_days;

        //ceil 대신 할 수 있는 것
        int res = 99 - p;
        total_days += res / sp.front() + 1;

        int cnt = 0;
        while(!pro.empty()){
            p = pro.front() + sp.front()*total_days;
            
            if(p < 100) break;
            else{
                cnt++;
                pro.pop();
                sp.pop();
            }
        }

        ans.push_back(cnt);
    }
    return ans;
}

