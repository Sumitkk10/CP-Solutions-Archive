#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
vector<int> graph[N];
int n, mx, str, end1, par[N];
bool vis[N];

void dfs(int node, int dis){
	if(dis > mx){
		str = node;
		mx = dis;
	}
	vis[node] = true;
	for(auto k : graph[node])
		if(!vis[k])
			dfs(k, dis + 1);
}

void dfs1(int node, int dis, int p){
    par[node] = p;
	if(dis > mx){
		end1 = node;
		mx = dis;
	}
	vis[node] = true;
	for(auto k : graph[node])
		if(!vis[k])
			dfs1(k, dis + 1, node);
}


void solve(){
	cin >> n;
	for(int i = 1; i <= n - 1; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1, 0);
	memset(vis, 0, sizeof vis);
	mx = 0;
	dfs1(str, 0, -1);
	vector<int> v;
	int cur = end1;
	while(cur != -1){
		v.push_back(cur);
		cur = par[cur];
	}
	if(v.size() == n){
		cout << n - 1 << '\n' << v[0] << ' ' << v[1] << ' ' << v[v.size() - 1] << '\n';
		return;
	}
	queue<int> q;
	vector<int> dis(n + 1, -1);
	for(auto k : v){
		dis[k] = 0;
		q.push(k);
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto k : graph[node]){
			if(dis[k] == -1){
				q.push(k);
				dis[k] = dis[node] + 1;
			}
		}
	}
	int mxx = 0, ans = 1;
	for(int i = 1; i <= n; ++i){
		if(dis[i] > mxx){
			mxx = dis[i];
			ans = i;
		}
	}
	cout << mx + mxx << '\n' << str << ' ' << ans << ' ' << end1 << '\n';
}

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}