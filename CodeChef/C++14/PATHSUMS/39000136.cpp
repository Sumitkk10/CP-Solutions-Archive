#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<ll> tree[N];
ll ans[N];
bool vis[N];

void dfs(int root, int dpt){
	vis[root] = 1;
	if(dpt % 2 == 0) ans[root] = 2;
	else ans[root] = 1;
	for(auto k : tree[root])
		if(!vis[k])
			dfs(k, dpt + 1);
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		for(int i = 0; i < n - 1; ++i){
			int u, v;
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		dfs(1, 0);
		for(int i = 1; i <= n; ++i){
			cout << ans[i] << " ";
			tree[i].clear();
			vis[i] = 0;
			ans[i] = 0;
		}
		cout << "\n";
	}
	return 0;
}
