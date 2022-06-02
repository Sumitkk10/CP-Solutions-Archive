#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N];
bool vis[N];
long long int ans = 0, val[N];

void dfs(int source){
	ans += val[source];
	vis[source] = 1;
	for(auto k : graph[source])
		if(!vis[k])
			dfs(k);
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i)
		cin >> val[i];
	vector<int> musems;
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			dfs(i);
			musems.push_back(ans);
			ans = 0;
		}
	}
	if(musems.size() < k){
		for(int i = 1; i <= n; ++i){
			vis[i] = 0;
			graph[i].clear();
		}
		cout << "-1\n";
		return;
	}
	sort(musems.begin(), musems.end());
	long long int i = 0, j = musems.size() - 1, realans = 0, cnt = 1;
	while(k--){
		if(cnt % 2){
			realans += musems[j];
			--j;
		}
		else{
			realans += musems[i];
			++i;
		}
		++cnt;
	}
	cout << realans << '\n';
	for(int i = 1; i <= n; ++i){
		vis[i] = 0;
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
