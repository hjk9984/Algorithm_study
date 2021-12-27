//완전탐색
//https://programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    //테두리 1즐이 갈색으로 칠해져있다.
    //가로의 길이는 노란색 격자 가로 길이 + 2
    //세로의 길이는 노란색 격자 세로 길이 + 2
    //가로,세로의 최소 길이는 3
    //(가로 - 2) * (세로 - 2) = yellow
    
    int width = 3;
    int height = 3;
    int area = brown + yellow; //카펫의 넓이를 이용해 가로, 세로의 길이 판단(실행 시간 줄이기 위해)
    int i = 3; //세로, 가로의 길이는 3보다 같거나 크므로
    while(1) {
        //width * height = area
        if(area % i == 0) {
            width = area / i;
            height = i;
            if((width-2)*(height-2) == yellow) {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }  
        }
        i++;
    }
    return answer;
}