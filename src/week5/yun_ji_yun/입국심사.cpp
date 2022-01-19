#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long min = 1;
    long long max = (long long)*max_element(times.begin(), times.end()) * (long long)n;
    

    while (min <= max) {
        long long people = 0;
        long long mid = (min + max) / 2;
        for(int i = 0; i < times.size(); i++) {
            people += mid / (long long)times[i];
        }

        if (people >= n) {
            max = mid - 1;
            answer = mid;
        } else {
            min = mid + 1;
        }
    }
    return answer;
}

/* 재귀로 풀려다가 실패
int n = 6;
int times[] = {7, 10};

long long binarySearch(long long min, long long max, int target) {
    if (min > max) {return -1;}

    long long people = 0;
    long long mid = (min + max) / 2;
    for(int i = 0; i < sizeof(times)/sizeof(times[0]); i++) {
        people += mid / (long long)times[i];
    }
    if (people == target)
        return mid;
    else if (people > target) 
        return binarySearch(min, mid - 1, target);
    else 
        return binarySearch(mid + 1, max, target);
}

int main() { 
    
    long long answer = 0;
    
    long long min = 1;
    long long max = (long long)*max_element(times, times + sizeof(times)/sizeof(times[0])) * (long long)n;
    
    answer = binarySearch(min, max, n);
    if (answer != -1)
        cout << answer << "\n";
}
*/
