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
	component[u] = v;
}

void solve(){
	int n;
	cin >> n;
	vector<pair<int, int> > a;
	for(int i = 1; i <= n; ++i)
		component[i] = i;
	for(int i = 1; i <= n - 1; ++i){
		int u, v;
		cin >> u >> v;
		if(find(u) == find(v))
			a.push_back({u, v});
		else
			merge(u, v);
	}
	cout << a.size() << "\n";
	int j = 0, x = find(1);
	for(int i = 2; i <= n; ++i){
		if(find(i) != x){
			cout << a[j].first << ' ' << a[j].second << ' ' << 1 << ' ' << i << "\n";
			merge(i, 1);
			++j;
		}
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