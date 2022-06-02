#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N];
ll dp[N], mx = 0;
bool vis[N];

void dfs(int source){
	dp[source] = vis[source] = 1;
	for(auto k : graph[source]){
		if(!vis[k]){
			dfs(k);
			dp[source] += dp[k];
		}
	}
}

void ans(int source, long long int sum){
	vis[source] = 1;
	mx = max(mx, sum + dp[source]);
	for(auto k : graph[source])
		if(!vis[k])
			ans(k, sum + dp[source]);
}

void solve(){
	long long int n;
	cin >> n;
	for(int i = 1; i <= n - 1; ++i){
		int x;
		cin >> x;
		graph[x].push_back(i + 1);
		graph[i + 1].push_back(x);
	}
	dfs(1);
	memset(vis, 0, sizeof(vis));
	ans(1, 0);
	cout << mx << '\n';
	mx = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i <= n; ++i)
		graph[i].clear();
	memset(dp, 0, sizeof(dp));
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}