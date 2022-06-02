#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n, v[N], u[N], col[N];
vector<int> graph[N];
bool ok = true;

void dfs(int node, int p, int color){
	if(color != -1 and color != col[p])
		ok = false;
	for(auto k : graph[node]){
		if(k != p){
			if(p == -1) dfs(k, node, -1);
			else dfs(k, node, col[k]);
		}
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n - 1; ++i){
		cin >> u[i] >> v[i];
		graph[u[i]].push_back(v[i]);
		graph[v[i]].push_back(u[i]);
	}
	for(int i = 1; i <= n; ++i) 
		cin >> col[i];
	int v1, v2;
	for(int i = 1; i <= n - 1; ++i){
		if(col[u[i]] != col[v[i]]){
			ok = false;
			v1 = u[i];
			v2 = v[i];
		}
	}
	if(ok){
		cout << "YES\n1\n";
		return;
	}
	ok = true;
	dfs(v1, -1, -1);
	if(ok){
		cout << "YES\n" << v1 << '\n';
		return;
	}
	ok = true;
	dfs(v2, -1, -1);
	if(ok){
		cout << "YES\n";
		cout << v2 << '\n';
		return;
	}
	cout << "NO\n";
}

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}