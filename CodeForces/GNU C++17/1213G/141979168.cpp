#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
long long n, q, component[N], comp_size[N], res;
vector<pair<int, int> > g[N];

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
	res -= (comp_size[u] * (comp_size[u] - 1))/2;
	res -= (comp_size[v] * (comp_size[v] - 1))/2;
	comp_size[v] += comp_size[u];
	component[u] = v;
	res += (comp_size[v] * (comp_size[v] - 1))/2;
}

void solve(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++){ 
		component[i] = i;
		comp_size[i] = 1;
	}
	for(int i = 0; i < n - 1;  ++i){
		int u, v, w;
		cin >> u >> v >> w;
		g[w].pb({u, v});
	}
	vector<long long> ans(q, 0), quer[N];
	for(int i = 0; i < q; ++i){
		int x;
		cin >> x;
		quer[x].push_back(i);
	}
	for(int i = 1; i < N; ++i){
		for(auto k : g[i]){
			if(find(k.first) != find(k.second))
				merge(k.first, k.second);
		}
		for(auto k : quer[i])
			ans[k] = res;
	}
	for(auto k : ans)
		cout << k << ' ';
	cout << '\n';
}
 
int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}