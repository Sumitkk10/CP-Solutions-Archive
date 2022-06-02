#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;
vector<pair<int, pair<int, int> > > edges;
int n, m, q, component[N], siz[N];

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
	if(component[u] == component[v]) return;
	siz[v] = siz[v] + siz[u];
	siz[u] = siz[v];
	component[u] = v;
}

void solve(){
	edges.clear();
	cin >> n >> m;
	for(int i = 0; i <= n; ++i){
		component[i] = i;
		siz[i] = 1;
	}
	for(int i = 0; i < m; ++i){
		int u, v, d;
		cin >> u >> v >> d;
		edges.pb({d, {u, v}});
	}
	sort(edges.begin(), edges.end());
	cin >> q;
	vector<pair<int, pair<int, int> > > quer;
	vector<int> ans(q);
	for(int i = 0; i < q; ++i){
		int s, x;
		cin >> s >> x;
		quer.pb({x, {s, i}});
	}
	sort(quer.begin(), quer.end());
	int cur = 0;
	for(auto k : edges){
		int c = k.F, u = k.S.F, v = k.S.S;
		while(cur < q and quer[cur].F < c){
			ans[quer[cur].S.S] = siz[find(quer[cur].S.F)];
			++cur;
		}
		merge(u, v);
	}
	while(cur < q){
		ans[quer[cur].S.S] = siz[find(quer[cur].S.F)];
		++cur;
	}
	for(auto k : ans)
		cout << k << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}