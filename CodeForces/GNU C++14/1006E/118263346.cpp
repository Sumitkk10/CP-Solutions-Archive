#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
int n, q, par[N], subtree[N], tin[N], tout[N], time1;
vector<int> graph[N], euler;

void dfs(int node){
	tin[node] = time1;
	euler.push_back(node);
	subtree[node] = 1;
	for(auto k : graph[node]){
		if(k != par[node]){
			++time1;
			dfs(k);
			subtree[node] += subtree[k];
		}
	}
	tout[node] = time1;
}

void solve(){
	cin >> n >> q;
	for(int i = 2; i <= n; ++i){
		int p;
		cin >> p;
		par[i] = p;
		graph[i].push_back(p);
		graph[p].push_back(i);
	}
	par[1] = -1;
	dfs(1);
	map<int, int> mp;
	for(int i = 0; i < euler.size(); ++i)
		mp[i] = euler[i];
	while(q--){
		int node, k;
		cin >> node >> k;
		if(subtree[node] < k){ 
			cout << "-1\n";
			continue;
		}
		int where = tin[node];
		cout << mp[where + k - 1] << '\n';
	}
}

int main() {
	fast;
	int t = 1;
    // cin >> t;
	while(t--)
		solve();
}