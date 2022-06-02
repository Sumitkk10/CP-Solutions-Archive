#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int n, k;
string s;

void solve(){
    cin >> n >> k >> s;
    long long int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);
    // no. of distinct subsqeuences of len j from 1..i;
    dp[1][1] = 1;
    dp[1][0] = 1;
    dp[0][0] = 1;
    for(int i = 2; i <= n; ++i){
        dp[i][0] = 1;
        for(int len = 1; len <= i; ++len){
            dp[i][len] = dp[i - 1][len] + dp[i - 1][len - 1];
            for(int j = i - 1; j >= 1; --j){
                if(s[i - 1] == s[j - 1]){
                    dp[i][len] -= dp[j - 1][len - 1];
                    break;
                }
            }
        }
    }
    long long ans = 0;
    for(int i = n; i >= 0; i--){
        long long int cur = dp[n][i];
        // cout << cur << ' ';
        if(k < 0) break;
        if(cur <= k){
            ans += dp[n][i] * (n-i);
            k -= cur;
        }
        else{
            ans += min(k, dp[n][i]) *(n-i);
            k = 0;
            break;
        }
    }
    if(k > 0) cout << "-1\n";
    else cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}