#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> v;
    int max_tile = brown + yellow;

    for(int i=2; i<=sqrt(max_tile); i++){
        if(max_tile % i == 0){
            v.push_back(i);
            v.push_back(max_tile / i);
        }
    }
    
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        int c = v[i];
        int r = v[v.size()-i-1];

        int num_b = 2*c + 2*r - 4;
        int num_y = max_tile - num_b;
        if(num_b == brown && num_y == yellow){
            answer.push_back(r);
            answer.push_back(c);
            break;
        }
    }


    return answer;
}