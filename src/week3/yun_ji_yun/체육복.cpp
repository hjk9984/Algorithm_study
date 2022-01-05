#include <iostream>
#include <string>
#include <vector>

#define MAX 30

using namespace std;

int main() {
    int answer = 0;

    int lost_tmp[] = {1,2,3};
    int reserve_tmp[] = {3,4};
    vector<int> lost;
    vector<int> reserve;
    for(int i = 0; i < sizeof(lost_tmp)/sizeof(lost_tmp[0]); i++) {
        lost.push_back(lost_tmp[i]);
    }
    for(int i = 0; i < sizeof(reserve_tmp)/sizeof(reserve_tmp[0]); i++) {
        reserve.push_back(reserve_tmp[i]);
    }

    //////////////////////////////////////////

    int n = 5;
    vector<int> students(n, 0);
    for(int i = 0; i < lost.size(); i++) {
        students[lost[i] - 1]--;
    }
    for(int i = 0; i < reserve.size(); i++) {
        students[reserve[i] - 1]++;
    }

    for(int i = 0; i < students.size(); i++) {
        if (students[i] == -1) {
            if (students[i - 1] == 1) {
                students[i]++;
                students[i - 1]--;
            } else if (students[i + 1] == 1) {
                students[i]++;
                students[i + 1]--;
            }
        }
    }

    for(int i = 0; i < students.size(); i++) {
        if (students[i] == 0 || students[i] == 1)
            answer++;
    }
    cout << answer << endl;
}

