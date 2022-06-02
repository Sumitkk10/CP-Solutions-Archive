#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define F first
#define S second
using namespace std;
const int N = 200002;
const int MOD = 1e9 + 7;
vector<int> graph[N];
long long n, par[N], subtree[N], in[N], out[N];

void dfs(int node, int p){
	par[node] = p;
	subtree[node] = 1;
	for(auto k : graph[node]){
		if(k == p) continue;
		dfs(k, node);
		subtree[node] += subtree[k];
		in[node] += in[k] + subtree[k];
	}
}

void dfs1(int node, int p){
     out[node] = in[p] - in[node] - subtree[node];
	out[node] += out[p] + n - subtree[node];
	for(auto k : graph[node]){
		if(k != p){
			dfs1(k, node);
		}
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n - 1; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	graph[0].clear();
	dfs(1, 0);
	in[0] = in[1] + subtree[1];
	dfs1(1, 0);
	long long ans = 0;
	for(int i = 1; i <= n; ++i){
	     // cout << out[i] << ' ';
		ans = max(ans, in[i] + out[i]);
	}
	cout << ans + n << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}