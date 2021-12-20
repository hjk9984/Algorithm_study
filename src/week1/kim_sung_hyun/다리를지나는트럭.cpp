#include<iostream>
#include <queue>


using namespace std;

struct truck{
    int weight;
    int dis;
    bool pass;
};


int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> wait;
    vector<truck> passing;
    int time = 0;
    
    for(int i=0; i<truck_weights.size(); i++)
        wait.push(truck_weights[i]);
        
    while(!wait.empty()) // 수정
    {
        bool passCheck = false;
        int sumWeight = 0;
        for(int i=0; i<passing.size(); i++)
        {
            passing[i].dis +=1;
            if(passing[i].dis == bridge_length)
                passing[i].pass = true;
            if(!passing[i].pass)
                sumWeight+= passing[i].weight;
        }
        int nWeight = wait.front();
        if(sumWeight+nWeight <= weight) // 무게 되면 다리올라감
        {
            truck t;
            t.dis = 0;
            t.weight =nWeight;
            t.pass = false;
            wait.pop();
            passing.push_back(t);
        }
            
        time++;
    }

	return time+bridge_length;
}