#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;
vector<pair<int, long long> > graph[N];
long long dp[N][(int) log2(N) + 2], n, q, r, lvl[N], dis[N];

void dfs(int source, int par, int level, long long distance){
	dp[source][0] = par;
	lvl[source] = level;
	dis[source] = distance;
	for(auto k : graph[source])
		if(k.first != par)
			dfs(k.first, source, level + 1, distance + k.second);
}

void init(){
	dfs(1, -1, 0, 0);
	for(int i = 1; i <= (log2(n)); ++i)
		for(int j = 1; j <= n; ++j)
			if(dp[j][i - 1] != -1)
				dp[j][i] = dp[dp[j][i - 1]][i - 1];
}

long long LCA(int u, int v){
	if(lvl[u] > lvl[v]) swap(u, v);
	long long d = lvl[v] - lvl[u];
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
    cin >> n >> q >> r;
    for(int i = 1; i <= n - 1; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    memset(dp, -1, sizeof dp);
    init();
    while(q--){
        int u, v;
        cin >> u >> v;
        int p = LCA(u, v);
        cout << dis[u] + dis[v] - 2 * dis[p] << "\n";
    }
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        for(int i = 1; i <= n; ++i){
            graph[i].clear();
            lvl[i] = dis[i] = 0;
        }
    }
	return 0;
}
