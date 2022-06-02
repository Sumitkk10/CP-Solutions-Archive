#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<pair<int, int> > graph[N];
int n, m, q;
bool vis[N];

bool dfs(int node, int col, int tar){
    vis[node] = true;
    if(node == tar)
        return 1;
    bool ok = 0;
    for(auto k : graph[node]){
        if(vis[k.first] or k.second != col) continue;
        ok |= dfs(k.first, col, tar);
    }
    return ok;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    cin >> q;
    while(q--){
        int u, v, ans = 0;
        cin >> u >> v;
        for(int col = 1; col <= m; ++col){
            for(int i = 1; i <= n; ++i) 
                vis[i] = false;
            ans += dfs(u, col, v);
        }
        cout << ans << "\n";
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
