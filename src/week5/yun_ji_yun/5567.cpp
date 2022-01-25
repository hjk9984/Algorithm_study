#include <iostream>
#include <queue>
using namespace std;

#define MAX 501

int n, len;
int cnt = 0;
vector<int> matrix[MAX];
bool visited[MAX] = {0, };
queue<int> q;

void bfs(int v) {
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i=1; i <= matrix[curr].size(); i++) {
            int next = matrix[curr][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                cnt++;
            }
        }
    }
}

int main() {
    cin >> n >> len;

    for(int i=0; i < len; i++) {
        int a, b;
        cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    bfs(1);

    cout << cnt;
}
