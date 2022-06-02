#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int n, m;
	cin >> n >> m;
	long long int dis[n + 5][n + 5];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j)
			dis[i][j] = INT_MAX;
		dis[i][i] = 0;
	}
	for(int i = 0; i < m; ++i){
		long long int u, v, c;
		cin >> u >> v >> c;
		dis[u][v] = c;
		dis[v][u] = c;
	}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	long long int mx = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			mx = max(mx, dis[i][j]);
	cout << mx << '\n'; 
	return 0;
}
