#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 305;
const int MOD = 1e9 + 7;
ll n, q, dp[N][N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> dp[i][j];
    cin >> q;
    for(int i = 1; i <= q; ++i){
        ll u, v, c;
        cin >> u >> v >> c;
        dp[u][v] = min(dp[u][v], c);
        dp[v][u] = min(dp[v][u], c);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                dp[i][j] = min({dp[i][j], c + dp[i][v] + dp[u][j], c + dp[i][u] + dp[v][j], dp[i][u] + dp[u][j], dp[i][v] + dp[v][j]});
        ll ans = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
                ans += dp[i][j];
        cout << ans << " ";
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}