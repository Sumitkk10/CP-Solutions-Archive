#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, m, component[N];

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
}

void solve(){
	cin >> n >> m;
	vector<pair<pair<int, int>, int> > edges;
	for(int i = 1; i <= m; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		edges.push_back({{u, v}, c});
	}
	long long ans = 0;
	for(int bit = 29; bit >= 0; --bit){
		long long cur = ans + (1 << bit) - 1;
		for(int i = 1; i <= n; ++i)
			component[i] = i;
		for(auto k : edges){
			ll cost = k.S, u = k.F.F, v = k.F.S;
			if((cost | cur) <= cur)
				merge(u, v);
		}
		set<int> s;
		for(int i = 1; i <= n; ++i){
			int x = find(i);
			s.insert(x);
		}
		if(s.size() > 1)
			ans += (1 << bit);
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