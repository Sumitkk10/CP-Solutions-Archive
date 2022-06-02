#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define F first
#define S second
using namespace std;
const int N = 200002;
const int MOD = 1e9 + 7;
vector<int> graph[N];
int n, par[N], in[N], out[N], a[N];

void dfs(int node, int p){
	par[node] = p;
	in[node] = (a[node] == 1 ? 1 : -1);
	for(auto k : graph[node]){
		if(k == p) continue;
		dfs(k, node);
		in[node] += max(0, in[k]);
	}
}

void dfs1(int node, int p){
	if(p != 0)
	     out[node] = max(0, out[p] + in[p] - max(0, in[node]));
	for(auto k : graph[node])
		if(k != p)
			dfs1(k, node);
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n - 1; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1, 0);
	dfs1(1, 0);
	for(int i = 1; i <= n; ++i)
		cout << in[i] + out[i] << ' ';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}