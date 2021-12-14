//스택, 큐
//공통 문제: 프린터

// return 요청한 문서가 몇번째로 인쇄되는 지

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

//풀이 1: 해시처럼 풀기
//arr를 이용하여 우선순위 별로 개수를 넣는다.
int solution(vector<int> priorities, int location) {
    // 0으로 초기화하기
    int arr[10] = {};
    queue<pair<int,int>> q;
    int max_n = 0, cnt=0;

    // arr에 우선순위 카운팅, 큐에 pair로 넣기
    for(int i=0; i<priorities.size(); i++){
        arr[priorities[i]]++;
        max_n = max(priorities[i], max_n);
        q.push({priorities[i], i});
    }

    while(!q.empty()){
        int p, l;
        while(!q.empty()){
            p = q.front().first;
            l = q.front().second;
            if(p == max_n){
                arr[p]--;
                q.pop();
                cnt++;

                if(arr[p]==0){
                    for(int i= p; i>0; i--){
                        if(arr[i]>0) {
                            max_n = i;
                            break;
                        }
                    }
                }
                break;
            }
            q.pop();
            q.push({p, l});
        }

        // 우리가 찾는 아이면 break
        if(location == l) break;
    }

    return cnt;
}

//풀이 2: 한번 풀고 나서 algorithm에 max_element라는 함수가 있다는 걸 알고 사용해보기
//max_element는 max함수가 두개의 값을 비교하는 것처럼 일련의 데이터를 비교한다.
//주의할 점은 iterator를 뱉는다. 시간복잡도는 O(n)
int solution2(vector<int> priorities, int location) {
    queue<int> printer;
    vector<int> sorted;

    //큐에 한번 다 넣는다.
    for(int i=0; i<priorities.size(); i++)
        printer.push(i);
    
    //돌면서 값 비교하기 O(n^2)이지만 데이터의 크기는 최대 100이므로 가능
    while(!printer.empty()){
        int now_ind = printer.front();
        printer.pop();
        if(priorities[now_ind] != *max_element(priorities.begin(), priorities.end())){
            printer.push(now_ind);
        }
        else{
            sorted.push_back(now_ind);
            priorities[now_ind] = 0;
        }
    }

    //이후 sorted에 들어가 있는 ind를 보면서 확인하기.
    //이렇게 짜지 말고 발견했을 때 바로 리턴하면 빠를 것 같다.
    for(int i=0; i<sorted.size();i++){
        if(sorted[i] == location) return i+1;
    }
}

