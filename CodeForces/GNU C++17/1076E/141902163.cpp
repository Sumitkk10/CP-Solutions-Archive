#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define F first
#define S second
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int n, dpt[N];
vector<pair<int, int> > mp[N];
long long pre[N], sub[N];
vector<int> g[N];

void dfs(int node, int par, int lvl){
	dpt[node] = lvl;
	for(auto k : g[node]){
		if(k != par)
			dfs(k, node, lvl + 1);
	}
}

void calc(int node, int par, long long add){
     pre[node] += add;
     long long sum = 0;
	for(auto k : mp[node]){
		sum += k.S;
		pre[node] += k.S;
		sub[k.F] += k.S;
	}
	for(auto k : g[node]){
		if(k == par) continue;
		calc(k, node, add - sub[dpt[node]] + sum);
	}
	for(auto k : mp[node])
		sub[k.F] -= k.S;
}

void solve(){
	cin >> n;
	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	int q;
	cin >> q;
	vector<long long> sum(n + 1, 0);
	dfs(1, 0, 0);
	while(q--){
		int node, k, val;
		cin >> node >> k >> val;
		mp[node].push_back({min(n - 1, dpt[node] + k), val});
	}
	calc(1, 0, 0);
	for(int i = 1; i <= n; ++i) cout << pre[i] << ' ';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}