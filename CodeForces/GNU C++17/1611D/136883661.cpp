#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n, par[N], p[N], root, branch[N], dpt[N];
vector<int> out[N];

void dfs(int root, int br, int lvl){
	branch[root] = br;
	dpt[root] = lvl;
	int cr = 0;
	for(auto k : out[root]){
		if(k != par[root]){
			dfs(k, br + cr, lvl + 1);
			++cr;
		}
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i)
		out[i].clear();
	for(int i = 1; i <= n; ++i){
		cin >> par[i];
		if(par[i] == i)
			root = i;
		else
			out[par[i]].push_back(i);
	}
	for(int i = 1; i <= n; ++i)
		cin >> p[i];
	if(p[1] != root){
		cout << "-1\n";
		return;
	}
	dfs(root, 1, 0);
	vector<ll> cost(n + 1, -1);
	ll sum = 0;
	cost[root] = 0;
	for(int i = 2; i <= n; ++i){
		if(cost[par[p[i]]] == -1){
			cout << "-1\n";
			return;
		}
		if(p[i - 1] == par[p[i]])
			cost[p[i]] = cost[par[p[i]]] + 1;
		else
			cost[p[i]] = sum + 1;
		sum = max(sum, cost[p[i]]);
	}
	for(int i = 1; i <= n; ++i){
		cout << cost[i] - cost[par[i]] << ' ';
	}
	cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}