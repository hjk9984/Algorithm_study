//개별문제
//https://programmers.co.kr/learn/courses/30/lessons/72410

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //step 1
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    
    //step 2
    for(int i=0; i<new_id.size();) {
        if (new_id[i] >= 'a' && new_id[i] <= 'z'
            || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'
            || new_id[i] >= '0' && new_id[i] <= '9') {
            i++;
        } else {
            new_id.erase(i, 1);
        }
    }
    
    //step 3
    for(int i=0; i<new_id.size()-1;) {
        if (new_id[i] == '.' && new_id[i+1] == '.') {
            new_id.erase(i+1, 1);
        } else {
            i++;
        }
    }
    
    //step 4
    if (new_id[0] == '.') {
        new_id.erase(0, 1);
    }
    if (new_id[new_id.size()-1] == '.') {
        new_id.erase(new_id.size()-1, 1);
    }
    
    //step 5
    if (new_id.size() == 0) {
        new_id = "a";
    }
    
    //step 6
    if (new_id.size() >= 16) {
        new_id.erase(15, new_id.size()-15);
    }
    if (new_id[new_id.size()-1] == '.') {
        new_id.erase(new_id.size()-1, 1);
    }
    
    //step 7
    if (new_id.size() <= 2) {
        for(int i=new_id.size(); i<3; i++){
            new_id += new_id[i-1];
        }
    }
    
    answer = new_id;
    
    
    return answer;
}