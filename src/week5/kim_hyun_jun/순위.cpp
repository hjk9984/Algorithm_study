#include <string>
#include <vector>
using namespace std;

bool arr[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(auto e : results)
        arr[e[0]][e[1]] = true;

    int i, j, k;
    for(k = 1; k <= n; k++){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                if(arr[i][k] && arr[k][j])
                    arr[i][j] = true;
            }
        }
    }

    for(i = 1; i<=n; i++){
        int cnt = 0;
        for(j = 1; j <= n; j++){
            if(arr[i][j] || arr[j][i]) 
                cnt++;
        }
        if(cnt == n - 1)
            answer++;
    }

    return answer;
}