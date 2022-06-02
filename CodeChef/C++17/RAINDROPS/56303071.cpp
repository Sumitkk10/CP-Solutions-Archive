#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, m;
vector<int> g[N];
vector<int> v;

void dfs(int node, int par, int len){
	bool leaf = true;
	for(auto k : g[node]){
		if(k != par){
			dfs(k, node, len + 1);
			leaf = false;
		}
	}
	if(leaf)
		v.pb(len);
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		g[i].clear();
	v.clear();
	for(int i = 1; i <= n - 1; ++i){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0, 1);
	sort(v.begin(), v.end());
	v.push_back(-1);
	int ct = 1;
	vector<pair<int, int> > ok;
	for(int i = 1; i < v.size(); ++i){
		if(v[i] == v[i - 1]) ++ct;
		else{
			ok.push_back({v[i - 1], ct});
			ct = 1;
		}
	}
	// for(auto k : mp) cout << k.F << ' '<< k.S << endl;
	long long ans = 0, cur = 0;
	for(int i = 1; i <= m; ++i){
		long long x;
		cin >> x;
		for(int j = 0; j < ok.size(); ++j){
			if(ok[j].F > x - cur) break;
			ans += max(0ll, (x - cur) - ok[j].F + 1) * ok[j].S;
		}
		cur = x;
	}
	cout << ans << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}