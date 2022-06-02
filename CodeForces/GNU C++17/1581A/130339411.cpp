#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long dp[N];

void solve(){
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}

int main(){
    fast;
    dp[1] = 1;
    for(long long i = 2; i < N; ++i)
        dp[i] = (dp[i - 1] * ((2*i) * (2*i - 1) % MOD) % MOD) % MOD;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
