#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int component[N], mn[N], mx[N];

int find(int a){
	while(true){
		if(a == component[a]) return a;
		component[a] = component[component[a]];
		a = component[a];
	}
}

void merge(int a, int b){
	int u = find(a), v = find(b);
	component[u] = v;
	mn[v] = min(mn[v], mn[u]);
	mn[u] = min(mn[u], mn[v]);
	mx[v] = max(mx[v], mx[u]);
	mx[u] = max(mx[u], mx[v]);
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		component[i] = i;
		mn[i] = i;
		mx[i] = i;
	}
	for(int i = 1; i <= m; ++i){
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		int j, cur = i;
		int till = mx[find(i)], mxx = till;
		for(j = i; j <= till; ++j)
			mxx = max(mxx, mx[find(j)]);
		for(j = i + 1; j <= mxx; ++j){
			if(find(j) != find(i)){
				merge(j, i);
				++ans;
			}
		}
		i = till;
	}
	cout << ans << '\n';
}

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}