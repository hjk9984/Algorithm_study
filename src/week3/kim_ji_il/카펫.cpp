/*  # 1번 풀이 (통과)
- 문제 : [카펫]  
- 접근 방식 : 
    문제 주어진 조건 대로 가로(x) , 세로(y) 에 대한 점화식 세우고 완전탐색 해줬더니 풀렸던 문제.
- 시간 복잡도 : ?
*/
#include <string>
#include <vector>
 
using namespace std;
 
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    bool flag =false;
    for(int x=3;;x++){
        for(int y =3;y<=x;y++){
            if((x-2)*(y-2)== yellow){
                if((2*x) + (2*y)-4 == brown){
                    answer.push_back(x);
                    answer.push_back(y);
                    flag = true;
                    break;
                }
            }
        }
        if(flag) break;
    }
    return answer;
}
