#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MOD = 15746;
const int N = 1e6 + 5;

int main(){
    fast;
    int n;
    cin >> n;
    int dp[n + 1] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    cout << dp[n] << '\n';
    return 0;
}