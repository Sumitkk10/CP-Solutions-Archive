#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 19;
const int MOD = 1e9 + 7;
int n, m, k;
long long a[N], x[N][N], dp[1 << N][N];

long long go(int cnt, int mask, int last){
    if(cnt == m)
        return 0;
    if(dp[mask][last] != -1)
        return dp[mask][last];
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        if(mask & (1 << i)) continue;
        ans = max(ans, go(cnt + 1, (mask | (1 << i)), i) + a[i] + x[last][i]);
    }
    return dp[mask][last] = ans;
}

void solve(){
    memset(dp, -1, sizeof dp);
    memset(x, 0, sizeof x);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= k; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        x[u][v] = c;
    }
    cout << go(0, 0, 0) << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
