#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<ll> graph[N];
ll degree[N];
bool vis[N];

void dfs(int source){
	vis[source] = true;
	for(auto k : graph[source]){
		degree[k]++;
		if(!vis[k])
			dfs(k);
	}
}

int main(){
	fast;
	ll n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i)
		if(!vis[i])
			dfs(i);
	ll visit[n + 1] = {0};
	while(1){
		bool ok = 0;
		for(int i = 1; i <= n; ++i){
			if(degree[i] >= k) continue;
			else if(visit[i] == 0){
				ok = 1;
				visit[i] = 1;
				for(auto k : graph[i])
					degree[k]--;
			}
		}
		if(!ok) break;
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i){
		// cout << i << " " << degree[i] << "\n";
		if(degree[i] >= k)
			++ans;
	}
	if(ans >= 1)
		cout << "YES\n" << ans;
	else
		cout << "NO\n";
	return 0;
}
