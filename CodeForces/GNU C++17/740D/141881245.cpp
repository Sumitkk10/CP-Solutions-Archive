#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
long long n, a[N], dp[N][20], dpt[N], pre[N], dis[N];
vector<pair<int, long long> > g[N];

void dfs(int node, int par, int lvl, long long length){
	dp[node][0] = par;
	dpt[node] = lvl;
	dis[node] = length;
	for(auto k : g[node])
		if(k.first != par)
			dfs(k.first, node, lvl + 1, length + k.second);
}

int find_kth(int node, int k){
	for(int i = 19; i >= 0; --i){
	   	if(k & (1 << i))
	        node = dp[node][i];
	}
	return node;
}

void calc(int node, int par){
	for(auto k : g[node]){
		if(k.first == par) continue;
		calc(k.first, node);
		pre[node] += pre[k.first];
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 2; i <= n; ++i){
		int p, e;
		cin >> p >> e;
		g[p].push_back({i, e});
		g[i].push_back({p, e});
	}
	memset(dp, -1, sizeof dp);
	dfs(1, 0, 0, 0);
	for(int j = 1; j < 20; ++j){
		for(int i = 1; i <= n; ++i){
			if(dp[i][j - 1] != -1)
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
	for(int i = 1; i <= n; ++i){
		int low = 1, high = dpt[i], ok = -1;
		while(low <= high){
			int mid = (low + high) / 2;
			int x = find_kth(i, mid);
			if(dis[i] - dis[x] <= a[i]){
				ok = x;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}
		if(ok == -1) continue;
		pre[dp[ok][0]] -= 1;
		pre[dp[i][0]] += 1;
	}
	calc(1, 0);
	for(int i = 1; i <= n; ++i)
		cout << pre[i] << ' ';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}