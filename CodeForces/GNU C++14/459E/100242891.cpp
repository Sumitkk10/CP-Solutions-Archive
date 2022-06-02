#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 3e5 + 1;
const int MOD = 1e9 + 7;
ll n, m;
vector<pair<int, int> > edges[N];
ll dp[N], add[N];

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		edges[c].push_back({u, v});
	}
	for(int i = 0; i < N; ++i){
		if(!edges[i].size()) continue;
		for(int j = 0; j < edges[i].size(); ++j){
			int u = edges[i][j].first, v = edges[i][j].second;
			add[v] = 0;
		}
		for(int j = 0; j < edges[i].size(); ++j){
			int u = edges[i][j].first, v = edges[i][j].second;
			add[v] = max(add[v], dp[u] + 1);
		}
		for(int j = 0; j < edges[i].size(); ++j){
			int u = edges[i][j].first, v = edges[i][j].second;
			dp[v] = max(add[v], dp[v]);
		}
	}
	long long int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, dp[i]);
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
