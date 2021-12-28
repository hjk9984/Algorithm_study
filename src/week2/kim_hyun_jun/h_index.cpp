#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define citations c

int solution(vector<int> citations) {
    int answer = 0;
    int cs = c.size();

    sort(c.begin(), c.end());

    int h = 0;
    for(int i=0; i<cs; i++){
        int cite = c[i];
        while(cite >= h){
            if(cite >= i+1 && cite <= cs-i){
                h = cite;
                break;
            }
            cite--; 
        }
    }

    answer = h;
    return answer;
}