
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
int opt[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int h =triangle.size();
	
	opt[0][0] = triangle[0][0];

	for (int i = 1; i < h; i++) {
		opt[i][0] = opt[i - 1][0] + triangle[i][0];
		opt[i][i] = opt[i - 1][i - 1] + triangle[i][i];
		for (int j = 1; j <= i-1; j++) {
			if (opt[i - 1][j - 1] + triangle[i][j] > opt[i - 1][j] + triangle[i][j])
				opt[i][j] = opt[i - 1][j - 1] + triangle[i][j];
			else opt[i][j] = opt[i - 1][j] + triangle[i][j];
		}
		
	}
    answer = *std::max_element(opt[h-1], opt[h-1] + h-1);
    
    
    return answer;
}