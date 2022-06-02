#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int n, a[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    long long dp[n + 1][n + 1];
    int ans = 0;
    for(int i = 0; i <= n; ++i){
    	for(int j = 0; j <= n; ++j)
    		dp[i][j] = INT_MIN;
    	dp[i][0] = 0;
    }
    for(int i = 1; i <= n; ++i){
    	for(int j = 1; j <= i; ++j){
    		if(dp[i - 1][j - 1] + a[i] >= 0){
    			// cout << i << ' ' << j << '\n';
    			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i]);
    		}
    		else dp[i][j] = dp[i - 1][j];
    		if(dp[i][j] >= 0)
    			ans = max(ans, j);
    	}
    }
    // cout << dp[1][1] << ' ';
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