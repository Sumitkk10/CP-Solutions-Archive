#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<ll> graph[N];
ll parent[N], siz[N];
bool vis[N];

void dfs(int i, int par){
	siz[i] = 1;
	parent[i] = par;
	vis[i] = true;
	for(auto edge : graph[i]){
		if(!vis[edge]){
			dfs(edge, i);
			siz[i] += siz[edge];
		}
	}
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n; 
		cin >> n;
		for(int i = 1; i <= n - 1; ++i){
			long long int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		dfs(1, 0);
		int mn = 1e9, ans;
		for(int i = 1; i <= n; ++i){
			int mx = 0, sum = 0;
			for(auto edge : graph[i]){
				if(edge == parent[i]) continue;
				mx = max(mx, (int) siz[edge]);
				sum += siz[edge];
			}
			mx = max(mx, (int) n - sum - 1);
			if(mx < mn){
				ans = i;
				mn = mx;
			}
		}
		cout << ans << " " << mn << "\n";
		for(int i = 1 ; i <= n; ++i){
			graph[i].clear();
			vis[i] = false;
		}
	}
	return 0;
}
