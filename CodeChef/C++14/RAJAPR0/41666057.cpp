#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> tree[N];
int dp[N][(int) (log2(N) + 2)], n, lvl[N], dist[N];
bool vis[N];

void dfs(int source, int parent, int level){
    dp[source][0] = parent;
    vis[source] = 1;
    lvl[source] = level;
    dist[source] = level;
    for(auto k : tree[source])
        if(!vis[k])
            dfs(k, source, level + 1);
}

void init(){
    dfs(1, -1, 0);
    for(int i = 1; i <= log2(n); ++i){
        for(int j = 1; j <= n; ++j){
            if(dp[j][i - 1] != -1)
                dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
}

int LCA(int u, int v){
    if(lvl[u] > lvl[v])
        swap(u, v);
    int d = lvl[v] - lvl[u];
    while(d){
        int jump = log2(d);
        v = dp[v][jump];
        d -= (1 << jump);
    }
    if(v == u)
        return v;
    for(int i = log2(n); i >= 0; --i){
        if(dp[v][i] != -1 and dp[v][i] != dp[u][i] and dp[u][i] != -1){
            v = dp[v][i];
            u = dp[u][i];
        }
    }
    return dp[v][0];
}

int main() {
    cin >> n;
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(dp, -1, sizeof dp);
    init();
    int q; 
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        int p = LCA(u, v);
        cout << ((dist[u] + dist[v] - 2 * dist[p]) % 2 ? "Odd\n" : "Even\n");
    }
	return 0;
}
