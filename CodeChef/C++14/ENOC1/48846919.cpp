#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int n, q, val[N];
vector<int> graph[N];
ll dp[N][(ll) log2(N)], lvl[N], xorr[N];

void dfs(int source, int par, int level){
    dp[source][0] = par;
    lvl[source] = level;
    xorr[source] = (val[source] ^ xorr[par]);
    for(auto k : graph[source])
        if(k != par)
            dfs(k, source, level + 1);
}

void init(){
    dfs(1, -1, 0);
    for(int i = 1; i <= (log2(n)); ++i)
        for(int j = 1; j <= n; ++j)
            if(dp[j][i - 1] != -1)
                dp[j][i] = dp[dp[j][i - 1]][i - 1];
}

ll LCA(int u, int v){
    if(lvl[u] > lvl[v]) swap(u, v);
    ll d = lvl[v] - lvl[u];
    while(d){
        int jump = log2(d);
        v = dp[v][jump];
        d -= pow(2, jump);
    }
    if(v == u) 
        return v;
    for(int i = log2(n); i >= 0; --i){
        if(dp[v][i] != -1 && dp[v][i] != dp[u][i]){
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[v][0];
}

void solve(){
    cin >> n >> q;
    for(int i = 0; i <= n; ++i){
        graph[i].clear();
        val[i] = 0;
        lvl[i] = 0;
        xorr[i] = 0;
    }
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(dp, -1, sizeof dp);
    init();
    while(q--){
        int u, v;
        cin >> u >> v;
        long long int p = LCA(u, v);
        cout << (xorr[u] ^ xorr[v] ^ val[p]) << '\n';
    }
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
