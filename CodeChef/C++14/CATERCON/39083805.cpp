#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll dp[N][2], a[N], n;
vector<ll> graph[N];
bool vis[N];

void dfs(int source){
	vis[source] = 1;
	int sum = 0, sum1 = 0;
	for(auto k : graph[source]){
		if(!vis[k]){
			dfs(k);
			sum += dp[k][0];
			sum1 += max(dp[k][0], dp[k][1]);
		}
	}
	dp[source][0] = sum1;
	dp[source][1] = sum + a[source];
}

int main(){
	fast;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n - 1; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
	return 0;
}
