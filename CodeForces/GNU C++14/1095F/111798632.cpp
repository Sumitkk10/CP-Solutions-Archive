#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long component[N], n, m, a[N];
vector<pair<long long, pair<int, int> > > edges;

int find(int u){
	while(true){
		if(u == component[u])
			return u;
		component[u] = component[component[u]];
		u = component[u];
	}
}

void merge(int a, int b){
	int u = find(a), v = find(b);
	component[u] = v;
}

long long MST(){
	long long ans = 0;
	for(int i = 0; i < edges.size(); ++i){
		long long cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if(find(u) == find(v)) continue;
		ans += cost;
		merge(u, v);
	}
	return ans;
}

void solve(){
	cin >> n >> m;
	long long mn = LLONG_MAX, node;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		component[i] = i;
		if(a[i] < mn){
			mn = a[i];
			node = i;
		}
	}
	for(int i = 1; i <= m; ++i){
		long long u, v, c;
		cin >> u >> v >> c;
		edges.push_back({c, {u, v}});
	}
	for(int i = 1; i <= n; ++i){
		if(node == i) 
			continue;
		edges.push_back({mn + a[i], {i, node}});
	}
	sort(edges.begin(), edges.end());
	cout << MST() << "\n";
}

int main(){
    fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}