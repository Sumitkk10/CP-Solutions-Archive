#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, q, tin[N], tout[N], timer, parent[N];
vector<int> g[N];

void dfs(int node, int par){
	tin[node] = ++timer;
	parent[node] = par;
	for(auto k : g[node])
		if(k != par)
			dfs(k, node);
	tout[node] = timer;
}

bool isanc(int u, int v){
	if(tin[u] <= tin[v] and tout[u] >= tout[v])
		return true;
	return false;
}

void solve(){
	cin >> n >> q;
	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	while(q--){
		int k;
		cin >> k;
		vector<pair<int, int> > v;
		for(int i = 0; i < k; ++i){
			int nodes;
			cin >> nodes;
			if(parent[nodes] == 0) parent[nodes] = 1;
			v.pb({tin[parent[nodes]], parent[nodes]});
		}
		sort(v.begin(), v.end());
		int cur = v[0].S;
		bool ok = 1;
		for(int i = 1; i < k; ++i){
			if(!isanc(cur, v[i].S)){
				ok = 0;
				break;
			}
			cur = v[i].S;
		}
		if(ok){
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}