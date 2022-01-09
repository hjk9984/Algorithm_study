#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end(),greater<int>());
    int sum =0;
    for(int i=0;i<people.size();i++){
       if(sum+ people[i] <=limit){
           sum += people[i];
       }
       else{
           answer++;
           sum = people[i];
        }
    }
    answer++;
   
   
    
    return answer;
}