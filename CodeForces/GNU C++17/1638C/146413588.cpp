#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
vector<int> g[N];
bool vis[N];

void dfs(int node){
	vis[node] = true;
	for(auto k : g[node]){
		if(!vis[k])
			dfs(k);
	}
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		vis[i] = 0;
		g[i].clear();
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		int mx = 0;
		for(int j = i; j <= n; ++j){
			mx = max(mx, a[j]);
			if(mx <= j){
				i = j;
				break;
			}
		}
		++ans;
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}