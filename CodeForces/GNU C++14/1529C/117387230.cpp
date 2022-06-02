#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
long long int n, dp[N][2];
pair<long long, long long> a[N];
vector<int> graph[N];

long long dfs(int node, bool which, int par){
	bool ok = false;
	if(dp[node][which] != -1)
		return dp[node][which];
	long long ans = 0, ans1 = 0, okk = 0;
	for(auto k : graph[node]){
		if(k != par){
			ok = 1;
			if(which == 0){
				ans = dfs(k, 0, node) + abs(a[node].first - a[k].first);
				ans1 = dfs(k, 1, node) + abs(a[node].first - a[k].second);
				okk += max(ans, ans1);
			}
			else{
				ans = dfs(k, 0, node) + abs(a[node].second - a[k].first);
				ans1 = dfs(k, 1, node) + abs(a[node].second - a[k].second);
				okk += max(ans, ans1);
			}
		}
	}
	if(!ok)
		return 0; 
	return dp[node][which] = okk;
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i].first >> a[i].second;
		dp[i][0] = dp[i][1] = -1;
	}
	for(int i = 1; i <= n - 1; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	long long ans = dfs(1, 0, -1);
	cout << max(ans, dfs(1, 1, -1)) << '\n';
	for(int i = 1; i <= n; ++i)	
		graph[i].clear();
}

int main() {
	fast;
	int t = 1;
     cin >> t;
	while(t--)
		solve();
}