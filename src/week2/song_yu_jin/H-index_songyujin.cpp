//정렬
//https://programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> citations) {
    int n = citations.size();
    sort(citations.rbegin(), citations.rend());
    //ex [6,5,3,1,0]
    
    //h는 citations.size 미만이고, h의 최대값을 찾는것이므로
    //h = citations.size() -1 에서 한개씩 감소 감소하면서
    //조건에 만족하면 break
    int h = citations.size() - 1;
    while(h > 0) {
        bool flag = true;
        for(int i=0; i<h; i++) {
            if (citations[i] < h) {
                flag = false;
                break;
            }
        }    
        if(flag == true) {
            for(int i=h; i<n; i++) {
                if (citations[i] > h) {
                    flag = false;
                    break;
                }
            }
            if(flag == true) {
                break;
            }
        }
        h--;
    }
    //테케 일부 실패하여 예외처리 
    //[10, 11, 12, 13] -> [4]
    //[0, 0, 0, 0] -> [0]
    if(h==0 && citations[0] != 0) {
        h = n;
    }
    return h;
}