/*  # 1번 풀이 (통과)
- 문제 : [체육복]  
- 접근 방식 : 
    student 벡터 하나 만들어서 체육복 개수를 나타내고 첫번째 학생부터 순회하면서 앞뒤로 체육복 빌릴 수 있으면 빌리고 answer++
    첫번째와 마지막 학생은 뒤나 앞을 비교 할 수 없기 때문에 동일한 로직을 했을때 out of range 오류가 날 수 있기 때문에 따로 처리.
- 시간 복잡도 :  
*/
#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n+1,1); 
    for(auto elem:lost) student[elem]--;
    for(auto elem:reserve) student[elem]++;
    
    for(int i=1;i<=n;i++){
        if(i==1 && student[i]<1){ // 첫번째 학생이 체육복 없을때
            if(student[i+1] >1)
            {
                student[i+1]--;
                answer++;
                continue;
            }
        }
        else if(i==n && student[i]<1){ // 마지막 학생이 체육복 없을때
            if(student[i-1] >1) {
                student[i-1]--;
                answer++;
                continue;
              }
        }
        else if(student[i]<1){ 
            if(student[i-1] >1) {
                student[i-1]--;
                answer++;
                continue;
              }
            else if(student[i+1]>1){
                student[i+1]--;
                answer++;
                continue;
            }
        }
        else{
            answer++;
        }
    }  
    return answer;
}