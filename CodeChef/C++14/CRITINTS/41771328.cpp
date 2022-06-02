#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1000 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N], ans;
bool vis[N];

void dfs(int source, int blocked){
    vis[source] = 1;
    for(auto k : graph[source])
        if(!vis[k] and !(k == blocked))
            dfs(k, blocked);
}

int main() {
    fast;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i){
        if(i == n)
            dfs(i - 1, i);
        else
            dfs(i + 1, i);
        bool ok = 0;
        for(int j = 1; j <= n; ++j){
            if(i == j) continue;
            if(!vis[j]) ok = 1;
            vis[j] = 0;
        }
        if(ok)
            ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(auto k : ans)
        cout << k << ' ';
    return 0;
}
