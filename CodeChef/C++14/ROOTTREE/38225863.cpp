#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<ll> graph[N];
bool vis[N];
ll indegree[N];

void dfs(int source){
	vis[source] = true;
	for(auto edge : graph[source]){
		indegree[edge]++;
		if(!vis[edge])
			dfs(edge);
	}
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		for(int i = 1; i <= n - 1; ++i){
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
		}
		for(int i = 1; i <= n; ++i){
			if(!vis[i])
				dfs(i);
		}
		long long int ct = 1, ans = 0;
		for(int i = 1; i <= n; ++i){
			// cout << indegree[i] << " ";
			if(indegree[i] == 0){
				ct = 0;
				continue;
			}
			else
				ans += indegree[i] - 1;
		}
		cout << ans + ct << "\n";
		for(int i = 1; i <= n; ++i){
			vis[i] = false;
			graph[i].clear();
			indegree[i] = 0;
		}
	}
	return 0;
}
