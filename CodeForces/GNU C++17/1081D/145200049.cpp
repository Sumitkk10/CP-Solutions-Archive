#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define pb push_back
#define F first
#define S second
const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, m, k, special[N], component[N], cp_siz[N];
vector<pair<int, pair<int, int> > > edges;

int find(int x){
	while(true){
		if(x == component[x])
			return x;
		component[x] = component[component[x]];
		x = component[x]; 
	}
}

void merge(int a, int b){
	int u = find(a), v = find(b);
	component[u] = v;
	cp_siz[v] += cp_siz[u];
}

void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i){
		component[i] = i;
		cp_siz[i] = 0;
	}
	for(int i = 0; i < k; ++i){
		int x;
		cin >> x;
		cp_siz[x] = 1;
		special[x] = true;
	}
	for(int i = 0; i < m; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		edges.pb({c, {u, v}});
	}
	sort(edges.begin(), edges.end());
	int ans = 0;
	for(int i = 0; i < m; ++i){
		int cost = edges[i].F;
		int u = edges[i].S.F, v = edges[i].S.S;
		if(find(u) == find(v)) continue;
		// cout << u << ' ' << v << endl;
		if(cp_siz[find(u)] and cp_siz[find(v)])
			ans = max(ans, cost);
		merge(u, v);
	}
	for(int i = 0; i < k; ++i)
		cout << ans << ' ';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}