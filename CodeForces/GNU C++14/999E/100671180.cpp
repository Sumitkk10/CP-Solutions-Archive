#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 5003;
const int MOD = 1e9 + 7;
vector<int> graph[N];
bool vis[N], visit[N];
int cnt;

void dfs(int source){
	vis[source] = 1;
	for(auto k : graph[source])
		if(!vis[k])
			dfs(k);
}

void dfs1(int source){
	visit[source] = 1;
	++cnt;
	for(auto k : graph[source])
		if(!vis[k] and !visit[k])
			dfs1(k);
}

void solve(){
	int n, m, start;
	cin >> n >> m >> start;
	for(int i = 1; i <= m; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	dfs(start);
	vector<pair<int, int> > v;
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			cnt = 0;
			dfs1(i);
			memset(visit, 0, sizeof(visit));
			v.push_back({cnt, i});
		}
	}
	sort(v.rbegin(), v.rend());
	int ans = 0;
	for(int i = 0; i < v.size(); ++i){
		if(!vis[v[i].second]){
			dfs(v[i].second);
			++ans;
		}
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
