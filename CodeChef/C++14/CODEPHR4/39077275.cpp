#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<pair<int, int> > graph[N];
bool vis[N];
ll dp[N];

void dfs(int source, int par){
	vis[source] = 1;
	if(par == -1) dp[source] = 0;
	else dp[source] += dp[par];
	for(auto k : graph[source]){
		if(!vis[k.first]){
			dp[k.first] += k.second;
			dfs(k.first, source);
		}
	}
}

int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 1; i <= n - 1; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({v, c});
		graph[v].push_back({u, c});
	}
	dfs(1, -1);
	ll ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += dp[i];
	cout << ans << "\n";
	return 0;
}
