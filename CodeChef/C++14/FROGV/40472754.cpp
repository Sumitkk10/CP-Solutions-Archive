#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6;
const int MOD = 1e9 + 7;
int component[N];

long long int find(int a){
	while(true){
		if(component[a] == a)
			return component[a];
		component[a] = component[component[a]];
		a = component[a];
	}
}

void merge(int a, int b){
	int u = find(a), v = find(b);
	component[v] = u;
}

void solve(){
	int n, k, p;
	cin >> n >> k >> p;
	pair<int, int> a[n];
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		a[i].first = x;
		a[i].second = i;
		component[i] = i;
	}
	sort(a, a + n);
	for(int i = 1; i < n; ++i)
		if((a[i].first - a[i - 1].first) <= k)
			merge(a[i].second, a[i - 1].second);
	while(p--){
		int u, v;
		cin >> u >> v;
		--u, --v;
		u = find(u), v = find(v);
		cout << (u == v ? "Yes\n" : "No\n"); 
	}
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}
