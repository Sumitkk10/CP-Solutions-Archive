#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, m;
vector<int> g[N];

void solve(){
	cin >> n >> m;
	for(int i = 0; i <= n; ++i)
		g[i].clear();
	for(int i = 1; i <= m; ++i){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	int dis[n + 1];
	for(int i = 1; i <= n; ++i)
		dis[i] = INT_MAX;
	dis[1] = 0;
	vector<bool> vis(N, 0);
	deque<int> q;
	q.push_back(1);
	while(!q.empty()){
		int node = q.front();
		q.pop_front();
		for(auto k : g[node]){
			if(dis[k] > dis[node]){
				dis[k] = dis[node];
				q.push_front(k);
			}
		}
		if(node + 1 <= n and dis[node + 1] > dis[node] + 1){
			dis[node + 1] = dis[node] + 1;
			q.push_back(node + 1);
 		}
 		if(node - 1 >= 1 and dis[node - 1] > dis[node] + 1){
 			dis[node - 1] = dis[node] + 1;
 			q.push_back(node - 1);
 		}
	}
	cout << dis[n] << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}