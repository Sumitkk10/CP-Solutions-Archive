#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
long long n, m, a[N][N], left_right_dp[N][N], right_left_dp[N][N], up_down_dp[N][N], down_up_dp[N][N];

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			left_right_dp[i][j] = a[i][j] + max(left_right_dp[i - 1][j], left_right_dp[i][j - 1]);
	for(int i = n; i >= 1; --i)
		for(int j = 1; j <= m; ++j)
			down_up_dp[i][j] = a[i][j] + max(down_up_dp[i + 1][j], down_up_dp[i][j - 1]);
	for(int i = n; i >= 1; --i)
		for(int j = m; j >= 1; --j)
			right_left_dp[i][j] = a[i][j] + max(right_left_dp[i][j + 1], right_left_dp[i + 1][j]);
	for(int i = 1; i <= n; ++i)
		for(int j = m; j >= 1; --j)
			up_down_dp[i][j] = a[i][j] + max(up_down_dp[i - 1][j], up_down_dp[i][j + 1]);
	long long ans = 0;
	for(int i = 2; i < n; ++i){
		for(int j = 2; j < m; ++j){
			ans = max(ans, left_right_dp[i][j - 1] + right_left_dp[i][j + 1] + down_up_dp[i + 1][j] + up_down_dp[i - 1][j]);
			ans = max(ans, left_right_dp[i - 1][j] + right_left_dp[i + 1][j] + down_up_dp[i][j - 1] + up_down_dp[i][j + 1]);
		}
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}