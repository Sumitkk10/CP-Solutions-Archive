#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 10;
const int MOD = 1e9 + 7;
bool vis[N];
ll ct = 0;
vector<pair<ll, ld> > covid[N];

void dfs(int source, ld tym){
	vis[source] = 1;
	++ct;
	for(auto i : covid[source])
		if(i.second > tym && vis[i.first] == 0)
			dfs(i.first, i.second);
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll a[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		ll mn = 1e18, mx = 1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < i; ++j)
				if(a[j] > a[i])
					covid[i].push_back({j, (ld) abs(i - j)/abs(a[i] - a[j])});
			for(int j = i + 1; j < n; ++j)
				if(a[j] < a[i])
					covid[i].push_back({j, (ld) abs(i - j)/abs(a[i] - a[j])});
		}
		for(int i = 0; i < n; ++i){
			dfs(i, 0);
			mx = max(mx, ct);
			mn = min(mn, ct);
			ct = 0;
			memset(vis, 0, sizeof(vis));
		}
		cout << mn << " " << mx << "\n";
		for(int i = 0; i < n; ++i) covid[i].clear();
	}
	return 0;
}