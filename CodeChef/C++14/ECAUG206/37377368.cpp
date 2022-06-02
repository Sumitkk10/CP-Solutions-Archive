#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<ll> graph[N];
bool vis[N];

void dfs(int source){
	vis[source] = true;
	for(auto i : graph[source])
		if(!vis[i])
			dfs(i);
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, m; 
		cin >> n >> m;
		for(int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		ll mar = 0;
		for(int i = 0; i < n; ++i){
			if(!vis[i]){
				++mar;
				dfs(i);
			}
		}
		cout << mar << "\n";
		for(int i = 0; i <= n; ++i){
			graph[i].clear();
			vis[i] = 0;
		}
	}
	return 0;
}
