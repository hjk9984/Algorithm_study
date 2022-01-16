#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

// bfs
// 연합이 있는 지 한번 보고(bfs) >> 몇개가 이어지는 지 모르기 때문에 >> 총 몇개, 어떤 것들이 연합인지 
// 있다면 계산을 통해서 평균값으로 대체
// 없다면 리턴

int N, L, R;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool visit[52][52] = {};
int arr[52][52];

bool valid(int n1, int n2){
    int n = n1 - n2;
    if(n < 0) n = -n;
    return n >= L && n <= R;
}

bool bfs(int r, int c){
    //개수와 길 구하기
    queue<pair<int, int>> q;
    q.push({r, c});
    visit[r][c] = true;

    // 평균값으로 대체할 연합 국가들을 저장할 벡터
    vector<pair<int, int>> v;
    v.push_back({r, c});

    while(!q.empty()){
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(visit[nr][nc]) continue;
            if(!valid(arr[nr][nc], arr[cur_r][cur_c])) continue;

            q.push({nr, nc});
            visit[nr][nc] = true;
            v.push_back({nr, nc});
        }
    }

    //연합 처리하기
    if(v.size() == 1) return false;
    
    int sum = 0;
    for(auto e : v)
        sum += arr[e.first][e.second];
    int mean = sum / v.size();

    for(auto e : v)
        arr[e.first][e.second] = mean;
    
    return true;
}


int solution(){
    int cnt = 0;

    // union check
    while(1){
        bool stop = true;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visit[i][j]) continue;
                if(bfs(i, j)) stop = false;
            }
        }
        if(stop) break;     // 연합이 없다면 프레이크
        cnt++;

        //visit 초기화하기
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++) visit[i][j] = false;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) 
            cin >> arr[i][j];
    }

    cout << solution();
}