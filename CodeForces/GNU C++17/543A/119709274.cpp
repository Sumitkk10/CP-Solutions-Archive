#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 505;
long long int MOD = 1e9 + 7;
long long n, m, k, bugs[N], dp[N][N];

void solve(){
	memset(dp, 0, sizeof dp);
	cin >> n >> m >> k >> MOD;
	for(int i = 1; i <= n; ++i)
		cin >> bugs[i];
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= m; ++j){
			for(int b = 0; b <= k; ++b){
				// we have first i programmers typing the first m lines in exactly b bugs;
				if(b + bugs[i] > 500) continue;
				dp[j + 1][b + bugs[i]] = (dp[j + 1][b + bugs[i]] + dp[j][b]) % MOD; 
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i <= k; ++i)
		ans = (ans + dp[m][i]) % MOD;
	cout << ans << '\n';
}

int main() {
	fast;
	int t = 1;
 	// cin >> t;
	while(t--)
		solve();
	return 0;
}