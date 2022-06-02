#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 301;
const int MOD = 20011;
int n, m, k, dp[N][N][N][3];
bool is_safe[N][N];

int go(int i, int j, int moves, int pre){
	if(i == n - 1 and j == m - 1)
		return (is_safe[i][j] and moves <= k);
	if(i >= n or j >= m or moves > k or !is_safe[i][j])
		return dp[i][j][moves][pre] = 0;
	if(dp[i][j][moves][pre] != -1)
		return dp[i][j][moves][pre];
	int ans = 0;
	if(pre == 0){
		ans = (ans + go(i + 1, j, moves + 1, 0)) % MOD;
		ans = (ans + go(i, j + 1, 1, 1)) % MOD;
	}
	else if(pre == 1){
		ans = (ans + go(i + 1, j, 1, 0)) % MOD;
		ans = (ans + go(i, j + 1, moves + 1, 1)) % MOD;
	}
	else{
		ans = (ans + go(i + 1, j, moves + 1, 0)) % MOD;
		ans = (ans + go(i, j + 1, moves + 1, 1)) % MOD;
	}
	return dp[i][j][moves][pre] = ans;
}

int main(){
	fast;
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> is_safe[i][j];
	cout << go(0, 0, 0, 2);
	return 0;
}
