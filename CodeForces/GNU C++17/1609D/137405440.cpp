#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
int n, q, component[N], ans[N];

int find(int x){
	while(1){
		if(x == component[x])
			return x;
		component[x] = component[component[x]];
		x = component[x];
	}
}

void merge(int u, int v){
	component[u] = v;
	ans[v] += ans[u];
}

void solve(){
	cin >> n >> q;
	int qqq[q + 1], qq[q + 1];
	for(int i = 1; i <= q; ++i)
		cin >> qq[i] >> qqq[i];
	for(int i = 1; i <= q; ++i){
		for(int j = 1; j <= n; ++j){
			component[j] = j;
			ans[j] = 1;
		}
		int cur = 0;
		for(int j = 1; j <= i; ++j){
			if(find(qq[j]) != find(qqq[j]))
				merge(find(qq[j]), find(qqq[j]));
			else
				++cur;
		}
		vector<int> v;
		vector<bool> vis(n + 1, 0);
		for(int j = 1; j <= n; ++j){
			if(vis[find(j)]) continue;
			v.push_back(ans[find(j)]);
			vis[find(j)] = true;
		}
		sort(v.rbegin(), v.rend());
		int sum = v[0];
		// if(i == q) cout << sum << ' ';
		for(int i = 1; i <= cur and i < v.size(); ++i)
			sum += v[i];
		cout << min(n - 1, sum - 1) << '\n';
	}
}

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
