#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N];
ll n, q;
bool vis[N];
ll parent[N], dis[N], a[N], dp[N][(ll) log2(N)];

void dfs(int source, int lvl, int par){
	vis[source] = 1;
	dis[source] = lvl; 
	parent[source] = par;
	dp[source][0] = par;
	for(auto k : graph[source])
		if(!vis[k])
			dfs(k, lvl + 1, source);
}

void init(){
	dfs(1, 0, -1);
	for(int i = 1; i <= (log2(n)); ++i)
		for(int j = 1; j <= n; ++j)
			if(dp[j][i - 1] != -1)
				dp[j][i] = dp[dp[j][i - 1]][i - 1];
}


long long int solve(int u, int v){
	if(dis[u] > dis[v]) swap(u, v);
	long long int d = dis[v] - dis[u];
	vector<ll> ans;
	ans.push_back(a[u]);
	while(d--){
		ans.push_back(a[v]);
		v = parent[v];
	}
	if(v != u){
		ans.push_back(a[v]);
		while(parent[u] != parent[v]){
			u = parent[u];
			v = parent[v];
			ans.push_back(a[u]);
			ans.push_back(a[v]);
		}
		if(parent[u] != -1)
			ans.push_back(a[parent[u]]);
	}
	sort(ans.begin(), ans.end());
	long long int mn = INT_MAX;
	for(int i = 1; i < ans.size(); ++i)
		mn = min(mn, ans[i] - ans[i - 1]);
	return mn;
}

ll LCA(int u, int v){
	if(dis[u] > dis[v]) swap(u, v);
	ll d = dis[v] - dis[u];
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

void test_cases(){
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(dp, -1, sizeof(dp));
	init();
	while(q--){
		int u, v;
		cin >> u >> v;
		long long int distance = dis[u] + dis[v] - (2 * dis[LCA(u, v)]);
		if(distance > 100){
			cout << "0\n";
			continue;
		}
		else
			cout << solve(u, v) << "\n";
	}
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		test_cases();
		for(int i = 0; i <= n; ++i){
			graph[i].clear();
			dis[i] = 0;
			vis[i] = 0;
			parent[i] = 0;
		}
	}
	return 0;
}
