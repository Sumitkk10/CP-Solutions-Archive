#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, q, dis[N], block, dpt[N], dp[N][20];
vector<int> g[N];
queue<int> red;

void dfs(int node, int par, int len){
	dp[node][0] = par;
	dpt[node] = len;
	for(auto k : g[node])
		if(k != par)
			dfs(k, node, len + 1);
}

void init(){
	dfs(1, 0, 0);
	for(int i = 1; i < 20; ++i){
		for(int j = 1; j <= n; ++j){
			if(dp[j][i - 1] != -1)
				dp[j][i] = dp[dp[j][i - 1]][i - 1];
		}
	}
}

void bfs(){
	while(!red.empty()){
		int node = red.front();
		red.pop();
		for(auto k : g[node]){
			if(dis[k] > dis[node] + 1){
				dis[k] = dis[node] + 1;
				red.push(k);
			}
		}
	}
}

int LCA(int u, int v){
	if(dpt[u] > dpt[v])
		swap(u, v);
	int diff = dpt[v] - dpt[u];
	while(diff > 0){
		int jump = log2(diff);
		v = dp[v][jump];
		diff -= (1 << jump);
	}
	if(v == u)
		return v;
	for(int i = 19; i >= 0; --i){
		if(dp[u][i] != -1 and dp[v][i] != dp[u][i]){
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[u][0];
}

void solve(){
	cin >> n >> q;
	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	block = sqrt(n);
	memset(dp, -1, sizeof dp);
	init();
	for(int i = 1; i <= n; ++i) dis[i] = n;
	red.push(1);
	dis[1] = 0;
	bfs();
	while(q--){
		int t, x;
		cin >> t >> x;
		if(t == 1){
			red.push(x);
			dis[x] = 0;
			if(red.size() == block)
				bfs();
		}
		else{
			int ans = dis[x];
			vector<int> res;
			while(!red.empty()){
				int node = red.front();
				res.pb(node);
				red.pop();
			}
			for(auto k : res)
				red.push(k);
			for(auto k : res){
				int p = LCA(x, k);
				ans = min(ans, dpt[x] + dpt[k] - 2*dpt[p]);
			}
			cout << ans << '\n';
		}
	}
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}