#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, col[N], sub[N], parent[N];
vector<int> g[N], trans[N];

void dfs(int node, int par){
	parent[node] = par;
	for(auto k : g[node]){
		if(k != par){
			dfs(k, node);
			sub[node] += sub[k];
		}
	}
	sub[node] += col[node];
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> col[i];
	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	queue<int> q;
	vector<bool> vis(n + 1, 0);
	for(int i = 1; i <= n; ++i){
		if(col[i]){
			q.push(i);
			vis[i] = true;
		}
		for(auto k : g[i]){
			if(k == parent[i]){
				if(col[k] == 1 or sub[1] - sub[i] > 1){
					trans[k].pb(i);
					// cout << k << ' ' << i << endl;
				}
			}
			else{
				if(col[k] == 1 or sub[k] > 1){
					trans[k].pb(i);
					// cout << k << ' ' << i << endl;
				}
			}
		}
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto k : trans[node]){
			if(!vis[k]){
				vis[k] = true;
				q.push(k);
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << vis[i] << ' ';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
    	solve();
	return 0;
}