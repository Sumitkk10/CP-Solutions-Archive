#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long n, a[N], dp[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    dp[1] = 0;
    for(int i = 1; i <= n; ++i)
        dp[i + 1] = (((2 * dp[i]) % MOD) + 2 - dp[a[i]] + MOD) % MOD;
    cout << dp[n + 1] << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
