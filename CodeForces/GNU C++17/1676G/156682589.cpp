/*
started at 20:35
*/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;
int n, p[N], black[N], white[N];
string s;
vector<int> g[N];

void dfs(int node, int p){
	black[node] = (s[node - 1] == 'B');
	white[node] = (s[node - 1] == 'W');
	for(auto k : g[node]){
		if(k != p){
			dfs(k, node);
			black[node] += black[k];
			white[node] += white[k];
		}
	}
}

void solve(){
	cin >> n;
	for(int i = 2; i <= n; ++i){
		cin >> p[i];
		g[i].pb(p[i]);
		g[p[i]].pb(i);
	}
	cin >> s;
	dfs(1, 1);
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += black[i] == white[i];
		black[i] = 0;
		white[i] = 0;
		g[i].clear();
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