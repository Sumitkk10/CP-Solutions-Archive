#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	int n, k;
	cin >> n >> k;
	long long a[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	long long dp[n + 1][k + 1], pre_sum[n + 1][k + 1];
	for(int i = 0; i <= n; ++i){
		for(int j = 1; j <= min(100, k); ++j){
			dp[i][j] = INT_MIN;
			pre_sum[i][j] = INT_MIN;
		}
		dp[i][0] = pre_sum[i][0] = 0;
		dp[0][1] = 0;
	}
	for(int i = 1; i <= n; ++i){
	    pre_sum[i][0] = 0;
		for(int j = 1; j <= min(i, k); ++j){
			dp[i][j] = max({pre_sum[i - 1][j - 1] + j*a[i], dp[i - 1][j] + j*a[i]});
	        pre_sum[i][j] = max(pre_sum[i - 1][j], dp[i][j]);
		}
	}
	long long ans = INT_MIN;
	for(int i = 1; i <= n; ++i)
	    ans = max(ans, dp[i][k]);
	cout << ans << '\n';
}

int main() {
	fast;
	int t = 1;
 	cin >> t;
	while(t--)
		solve();
	return 0;
}