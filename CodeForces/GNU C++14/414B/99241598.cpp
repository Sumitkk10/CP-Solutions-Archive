#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, kk;
	cin >> n >> kk;
	long long int dp[n + 1][kk + 1]; // ans when i place nth number at the kth pos
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; ++i)
		dp[i][1] = 1; // as we can place anything at the first pos;
	for(int i = 2; i <= kk; ++i){
		for(int j = 1; j <= n; ++j){
			for(int k = 1; k * k <= j; ++k){
				if(j % k == 0){
					dp[j][i] = (dp[j][i] + dp[k][i - 1]) % MOD;
					if(j / k != k)
						dp[j][i] = (dp[j][i] + dp[j / k][i - 1]) % MOD;
				}
			}
		}
	}
	// cout << dp[3][2] << ' ';
	long long int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = (ans + dp[i][kk]) % MOD;
	cout << ans << "\n";
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
