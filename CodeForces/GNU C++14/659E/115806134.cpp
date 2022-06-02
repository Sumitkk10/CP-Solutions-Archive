#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, m;
vector<int> graph[N];
bool vis[N], ok;

void dfs(int source, int p){
    vis[source] = true;
    for(auto k : graph[source]){
        if(vis[k] and k != p) ok = 1;
        if(!vis[k])
            dfs(k, source);
    }
}

void solve(){
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ct = 0;
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            dfs(i, -1);
            if(!ok) ++ans;
            ok = 0;
            ++ct;
        }
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
