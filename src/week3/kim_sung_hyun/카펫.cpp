#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    for(int he=3; he<2500; he++)
    {
        bool flag = false;
        for(int we=he; we<2500; we++)
        {
            int val = we+we+he+he-4;
            if(val== brown && we*he-val == yellow)
            {
                answer[0] = we;
                answer[1] = he;
                flag = true;
            }
        }
        if(flag)
            break;
    }
    
    return answer;
}