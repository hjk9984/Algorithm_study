#include <iostream>
#include <queue>
using namespace std;

#define MAX 101

int computer, network;
int cnt = 0;
int matrix[MAX][MAX];
bool visited[MAX] = {0, };
queue<int> q;

void bfs(int v) {
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int i=1; i <= computer; i++) {
            if (matrix[v][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }
}

int main() {
    cin >> computer >> network;

    for(int i=0; i < network; i++) {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    bfs(1);

    cout << cnt;
}
