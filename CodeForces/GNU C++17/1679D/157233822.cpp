#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;
long long n, m, k, val[N], col[N], mx, dpp[N], indegree[N], LPD[N];
vector<int> g[N];
bool vis[N], cycle;
queue<int> q;

void topo(long long mid){
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto kk : g[x]){
			if(!vis[kk] and val[kk] <= mid){
				indegree[kk]--;
				if(indegree[kk] == 0){
					q.push(kk);
					vis[kk] = true;
				}
				LPD[kk] = max(LPD[kk], LPD[x] + 1);
			}
		}
	}
}

void dfss(int source, long long mid){
	vis[source] = 1;
	for(auto kk : g[source]){
		indegree[kk]++;
		if(!vis[kk] and val[kk] <= mid)
			dfss(kk, mid);
	}
}

void dfs(int node, long long mid){
	col[node] = 1;
	for(auto kk : g[node]){
		if(val[kk] > mid)
			continue;
		if(col[kk] == 1)
			cycle = true;
		else if(!col[kk])
			dfs(kk, mid);
	}
	col[node] = 2;
}


bool check(long long mid){
	for(int i = 1; i <= n; ++i){
		col[i] = 0;
		vis[i] = 0;
                indegree[i] = 0;
                LPD[i] = 0;
	}
	cycle = 0;
	for(int i = 1; i <= n; ++i){
		if(!col[i] and val[i] <= mid){
			dfs(i, mid);
			if(cycle)
				return true;
		}
	}
	for(int i = 1; i <= n; ++i)
		if(!vis[i] and val[i] <= mid)
			dfss(i, mid);
	for(int i = 1; i <= n; ++i)
		vis[i] = 0;
	for(int i = 1; i <= n; ++i){
		if(!indegree[i] and val[i] <= mid){
			q.push(i);
			vis[i] = true;
		}
	}
	topo(mid);
	long long ans = 0;
	for(int i = 1; i <= n; ++i){
	    if(val[i] <= mid)
		    ans = max(ans, LPD[i] + 1);
	}
	return (ans >= k);
}

void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		cin >> val[i];
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
	}
	long long low = 1, high = 1e9, ans = -1;
	while(low <= high){
		long long mid = (low + (high - low) / 2);
		if(check(mid)){
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}