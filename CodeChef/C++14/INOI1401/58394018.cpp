#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 300 + 5, MOD = 20011; 
long long n, m, k, dp[N][N][N][3];
bool a[N][N];

long long go(int i, int j, int left, int pre){
	if(i == n - 1 and j == m - 1)
		return 1;
	if(i >= n or j >= m or a[i][j] == 0 or left < 0)
		return 0;
	if(dp[i][j][left][pre] != -1)
		return dp[i][j][left][pre];
	long long ans = 0;
	if(pre == 0){
		ans = (ans + go(i + 1, j, left - 1, 1)) % MOD;
		ans = (ans + go(i, j + 1, left - 1, 2)) % MOD;
	}
	else if(pre == 1){
		if(left > 0)
			ans = (ans + go(i + 1, j, left - 1, pre)) % MOD;
		ans = (ans + go(i, j + 1, k - 1, 2)) % MOD;
	}
	else{
		if(left > 0)
			ans = (ans + go(i, j + 1, left - 1, pre)) % MOD;
		ans = (ans + go(i + 1, j, k - 1, 1)) % MOD;
	}
	return dp[i][j][left][pre] = ans;
}

void solve(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> a[i][j];
	memset(dp, -1, sizeof dp);
	cout << go(0, 0, k, 0) << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}