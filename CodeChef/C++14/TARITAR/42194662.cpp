#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
vector<int> graph[N];
int n, q, x, dp[N][20], lvl[N];
bool vis[N];

void dfs(int source, int level, int par){
    vis[source] = true;
    lvl[source] = level;
    dp[source][0] = par;
    for(auto k : graph[source])
        if(!vis[k])
            dfs(k, level + 1, source);
}

void init(){
    dfs(x, 0, -1);
    for(int i = 1; i <= log2(n); ++i)
        for(int j = 1; j <= n; ++j)
            if(dp[j][i - 1] != -1)
                dp[j][i] = dp[dp[j][i - 1]][i - 1];
}

bool is_ancestor(int a, int b){
    int u = lvl[a], v = lvl[b];
    if(a == b)
        return true;
    if(u == v)
        return false;
    if(u < v)
        return false;
    int d = u - v;
    while(d){
        int jump = log2(d);
        a = dp[a][jump];
        d -= (1LL << jump);
    }
    if(a == b)
        return true;
    return false;
}

void solve() {
    cin >> n >> q >> x;
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    init();
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << (is_ancestor(b, a) ? "Taran\n" : "Sakub-Jafin\n");
    }
    for(int i = 1; i <= n; ++i){
        graph[i].clear();
        lvl[i] = vis[i] = 0;
    }
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}