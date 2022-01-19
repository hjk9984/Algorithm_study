#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    int left = 1, right = distance;
    
    while (left <= right) {
        int removed = 0;
    	int mid_distanceMin = (left + right) / 2;
        
        int prev = 0;
        for(int i = 0; i < rocks.size(); i++) {
            if (rocks[i] - prev < mid_distanceMin)
                removed++;
            else
                prev = rocks[i];
        }
        if (distance - prev < mid_distanceMin) 
            removed++;
        
        // 이해 되면서도 안되는 부분
        if (removed <= n) {
            answer = max(answer, mid_distanceMin);
            left = mid_distanceMin + 1;
        } else {
            right = mid_distanceMin - 1;
        }
    }
    return answer;
}
