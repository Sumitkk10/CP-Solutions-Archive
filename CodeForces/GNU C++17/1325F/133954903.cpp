#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define F first
#define S second
using namespace std;
const int N = 100004;
const int MOD = 1e9 + 7;
vector<int> graph[N];
int n, m, par[N], vis[N], sq, timer, tin[N];
bool ans[N];

void dfs(int node, int p){
	par[node] = p;
	vis[node] = 1;
	tin[node] = ++timer; 
	for(auto k : graph[node]){
		if(!vis[k]){
			dfs(k, node);
			continue;
		}
		if(vis[k]){
			if(tin[node] - tin[k] + 1 >= sq){
				cout << "2\n" << tin[node] - tin[k] + 1 << '\n';
				vector<int> ans;
				int cur = node;
				while(cur ^ k){
					ans.push_back(cur);
					cur = par[cur];
				}
				ans.push_back(cur);
				reverse(ans.begin(), ans.end());
				for(auto k : ans)
					cout << k << ' ';
				exit(0);
			}
		}
	}
	vis[node] = 2;
	--timer;
	if(!ans[node]){
	     for(auto k : graph[node])
	          ans[k] = 1;
	}
}

void solve(){
	cin >> n >> m;
	while(sq*sq < n)
		++sq;
	for(int i = 1; i <= m; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1, 0);
	int ct = 0, done = 0;
	cout << "1\n";
	for(int i = 1; i <= n; ++i){
	     if(done == sq) break;
		if(!ans[i]){
			cout << i << ' ';
			++done;
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