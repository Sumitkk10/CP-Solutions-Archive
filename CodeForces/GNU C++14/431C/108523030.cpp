#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, k, d, dp[N][2];

long long int go(long long sum, bool ok){
    if(sum < 0)
        return 0;
    if(sum == 0 and ok == 0)
        return 0;
    if(sum == 0 and ok == 1)
        return 1;
    if(dp[sum][ok] != -1)
        return dp[sum][ok];
    long long ans = 0;
    for(int i = 1; i <= k; ++i)
        ans = (ans + go(sum - i, ok | (i >= d))) % MOD;
    return dp[sum][ok] = ans;
}

void solve(){
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> d;
    cout << go(n, 0) << "\n";
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}