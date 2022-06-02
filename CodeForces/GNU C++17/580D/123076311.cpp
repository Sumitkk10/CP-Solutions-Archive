#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 20;
const int MOD = 1e9 + 7;
long long int dp[1 << N][N], add[N][N];

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    long long a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < k; ++i){
        int x, y, c;
        cin >> x >> y >> c;
        --x, --y;
        add[x][y] = c;
    }
    for(int i = 0; i < n; ++i)
        dp[1 << i][i] = a[i];
    long long ans = 0;
    for(int i = 0; i < (1LL << n); ++i){
        for(int j = 0; j < n; ++j){
            if(!(i & (1LL << j))) continue;
            for(int k = 0; k < n; ++k){
                if(!(i & (1 << k))) continue;
                dp[i][j] = max(dp[i][j], add[k][j] + a[j] + dp[i ^ (1 << j)][k]);
            }
        }
    }
    for(int i = 0; i < (1 << n); ++i){
        if(__builtin_popcount(i) != m) continue;
        for(int j = 0; j < n; ++j)
            ans = max(ans, dp[i][j]);
    }
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
