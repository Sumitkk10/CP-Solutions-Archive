#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const long long int MOD = 1000000007;
const long long int N = 1e6 + 5;
long long int dp[N], pre_sum[N];

void solve(){
    int a, b;
    cin >> a >> b;
    cout << (pre_sum[b] - pre_sum[a - 1]) % MOD << "\n";
}

int main() {
    fast;
    long long int tt, k;
    cin >> tt >> k;
    dp[0] = 1;
    for(long long int i = 1; i <= k - 1; ++i){
        dp[i] = dp[i - 1] % MOD;
        pre_sum[i] = (pre_sum[i - 1] + dp[i]);
    }
    dp[k] = (dp[k - 1] + 1) % MOD;
    pre_sum[k] = (pre_sum[k - 1] + dp[k]) % MOD;
    for(long long int i = k + 1; i <= N; ++i){
        dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
        pre_sum[i] = (pre_sum[i - 1] + dp[i]);
    }
    while(tt--)
        solve();
    return 0;
}