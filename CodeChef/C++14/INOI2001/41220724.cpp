#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N];
bool vis[N];
int small = INT_MAX, large = 0, cnt = 0;
ll sum = 0;

void dfs(int source){
	vis[source] = 1;
	small = min(small, source);
	large = max(large, source);
	++cnt;
	for(auto k : graph[source])
		if(!vis[k])
			dfs(k);
}

void dfs1(int source, int lvl){
	sum += lvl;
	vis[source] = 1;
	for(auto k : graph[source])
		if(!vis[k])
			dfs1(k, lvl + 1);
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> even, odd;
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			dfs(i);
			if(cnt % 2 == 0)
				even.push_back(small);
			else
				odd.push_back(large);
			large = 0;
			small = INT_MAX;
			cnt = 0;
		}
	}
	for(int i = 1; i <= n; ++i)
		vis[i] = false;
	ll even_sum = 0, odd_sum = 0;
	for(auto k : even){
		dfs1(k, 1);
		even_sum += sum;
		sum = 0;
	}
	for(auto k : odd){
		dfs1(k, 1);
		odd_sum += sum;
		sum = 0;
	}
	cout << even_sum << ' ' << odd_sum << '\n';
	for(int i = 1; i <= n; ++i){
		vis[i] = false;
		graph[i].clear();
	}
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
