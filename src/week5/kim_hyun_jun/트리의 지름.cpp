#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100005

int n, global_ans=0, dd;
vector<pair<int, int>> v[MAX];

void dfs(int x, int pre, int dist){
    if(dist > global_ans){
        global_ans = dist;
        dd = x;
    }

    for(auto& elem : v[x]){
        int node = elem.first;
        int w = elem.second;
        if(node == pre) continue;
        dfs(node, x, dist+w);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int num_node, n1, n2;
    for(int i=1;i<=n;i++){
        cin >> num_node;
        while(1){
            cin >> n1;
            if(n1 == -1) break;
            cin >> n2;
            v[num_node].push_back({n1, n2});
        }
    }

    
    dfs(1, 0, 0);
    dfs(dd, 0, 0);

    cout << global_ans;
}