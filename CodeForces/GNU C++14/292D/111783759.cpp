#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
int component[N];

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
	if(u == v)
    	return;
	component[v] = u;
}

void solve(){
	int n, m;
	cin >> n >> m;
	int edges[m + 1][2];
	for(int i = 1; i <= m; ++i)
		cin >> edges[i][0] >> edges[i][1];
	int k;
	cin >> k;
	while(k--){
		int l, r;
		cin >> l >> r;
		for(int i = 1; i <= n; ++i)
			component[i] = i;
		for(int i = 1; i <= m; ++i){
			if(i >= l and i <= r)
			    continue;
			// cout << find(edges[i][0]) << ' ' << find(edges[i][1]) << " || ";
			merge(edges[i][0], edges[i][1]);
		}
		unordered_map<int, bool> mp;
		for(int i = 1; i <= n; ++i)
			mp[component[find(i)]] = true;
		cout << mp.size() << "\n";
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