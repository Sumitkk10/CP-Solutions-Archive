#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
using namespace std;
const int N = 700 + 5, MOD = 1e9 + 7; 
int n, k, b[N], v[N], dp[N][N];
vector<int> nxt[N];

long long go(int i, int j){
	if(i >= j or i > n or j <= 0)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	long long ans = go(i + 1, j);
	ans = max(ans, go(i, j - 1));
	for(auto z : nxt[i]){
		if(z > j) break;
		ans = max(ans, go(i + 1, z - 1) + go(z + 1, j) + v[i] + v[z]);
	}
	return dp[i][j] = ans;
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	for(int i = 1; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j)
			if(b[j] == b[i] + k)
				nxt[i].pb(j);
	}
	memset(dp, -1, sizeof dp);
	cout << go(1, n) << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}