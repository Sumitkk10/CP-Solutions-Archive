#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e7 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	long long int dist[n + 1][n + 1];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			dist[i][j] = INT_MAX;
	for(int i = 0; i < m; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	for(int i = 1; i <= n; ++i)
		dist[i][i] = 0;
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int q;
	cin >> q;
	while(q--){
		int u, v;
		cin >> u >> v;
		// cout << dist[u][v] << ' ';
		cout << (dist[u][v] > k ? "NO\n" : "YES\n");
	}
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
