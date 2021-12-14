//스택 큐
//공통문제: 다리를 지나는 트럭

// return 모든 트럭이 지나갈 때까지의 시간
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct state{
    int w;
    int l;
};

//풀이 1: bridge위에 있는 트럭을 state로 표현하고 이를 bridge라는 벡터로 관리
//이렇게 상태가 변화될 때 들어갈 때와 나올 때를 유심히 보면서 처리하기
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    vector<state> bridge;

    for(auto e:truck_weights)
        q.push(e);
    
    int weight_available = weight;
    int num_pass = 0;
    //O(n)
    while(!q.empty()){
        //1초 경과하기
        //오르자마자 시간 계산하는 게 더 효율적일 수 있다고 생각됨
        //먼저 경과를 해야지 올라갈 수 있는 지 확인 가능
        for(int i=num_pass; i<bridge.size(); i++){
            bridge[i].l++;
            if(bridge[i].l >= bridge_length){
                weight_available += bridge[i].w;
                num_pass++;
            }
        }
        
        //다리에 올라가도 되는 지 확인
        int w = q.front();
        if(w <= weight_available){          //올라갈 수 있으면 l=0으로 하고 bridge에 넣기
            bridge.push_back({w, 0});
            q.pop();
            weight_available -= w;
        }    

        answer++;
    }

    //맨 마지막 차가 도착까지 남은 거리 더하기
    state last = *(bridge.end()-1);
    answer += bridge_length - last.l;

    return answer;
}

//풀이 2: 위의 풀이를 더 효율적으로 풀기 위해서
//1초씩 경과가 아니라 매 루트마다 차를 올리거나 내리도록 함
//효율적일 수는 있으나 구현하는 데 좀 빡쎄다.
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    vector<state> bridge;

    for(auto e:truck_weights)
        q.push(e);
    
    int cur_w = 0;
    int num_pass = 0;
    while(!q.empty()){
        //트럭을 올릴 수 있으면 
        if(cur_w + q.front() <= weight){
            bridge.push_back({q.front(), -1});
            cur_w += q.front();
            q.pop();
            
            //올라오는 트럭을 -1에 올리고 다들 한칸씩 전진
            for(int i=num_pass; i<bridge.size(); i++){
                bridge[i].l++;
                if(bridge[i].l >= bridge_length){
                    num_pass++;
                    cur_w -= bridge[i].w;
                }
            }
            answer++;
        }
        else{       //못 올린다면? 맨 앞의 트럭을 바로 빼기
            int dist = bridge_length - bridge[num_pass].l;
            for(int i=num_pass; i<bridge.size(); i++)
                bridge[i].l += dist;
            cur_w -= bridge[num_pass].w;
            num_pass++;
            answer += dist;     //맨 앞 트럭이 간 만큼 초 더하기
            
            //무게 계산하고 차 올릴 수 있으면 올리기
            if(cur_w + q.front() <= weight){
                bridge.push_back({q.front(), 0});
                cur_w += q.front();
                q.pop();
            }

        }
        
    }

    //맨 마지막 차가 도착까지 남은 거리 더하기
    state last = *(bridge.end()-1);
    answer += bridge_length - last.l;

    return answer;
}