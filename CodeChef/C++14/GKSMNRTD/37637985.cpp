#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
ll n, a[N], mn = INT_MAX, j;
vector<ll> graph[N], towns[N];
bool vis[N];

void dfs(int source){
	vis[source] = true;
	towns[j].push_back(source);
	for(auto edge : graph[source])
		if(!vis[edge])
			dfs(edge);
}

int main(){
	fast;
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	ll k; cin >> k;
	for(int i = 0; i < k; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			dfs(i);
			++j;
		}
	}
	ll ans = 1;
	for(int i = 0; i < j; ++i){
		mn = INT_MAX;
		int ct = 0;
		for(int k = 0; k < towns[i].size(); ++k)
			mn = min(mn, a[towns[i][k]]);
		for(int k = 0; k < towns[i].size(); ++k)
			if(mn == a[towns[i][k]])
				++ct;
		ans = ans * ct % MOD;
	}
	cout << ans;
	return 0;
}
