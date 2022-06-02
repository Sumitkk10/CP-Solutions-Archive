#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 200 + 5;
const int MOD = 1e9 + 7;
ll n, m, a[N], b[N], dp[N][5004];

ll go(int i, int mask){
    if(i == n)
        return mask;
    if(dp[i][mask] != -1)
        return dp[i][mask];
    ll ans = INT_MAX;
    for(int j = 0; j < m; ++j)
        ans = min(ans, go(i + 1, (mask | (a[i] & b[j]))));
    return dp[i][mask] = ans;
}

void solve(){
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i)
        cin >> b[i];
    cout << go(0, 0) << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}