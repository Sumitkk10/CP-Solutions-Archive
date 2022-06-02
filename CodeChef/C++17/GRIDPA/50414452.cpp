#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
int n, k, val[N][N];
char a[N][N];

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> val[i][j];
    vector<vector<vector<ll> > > dp(n + 1, vector<vector<ll> > (n + 1, vector<ll> (k + 1, INT_MIN)));
    dp[1][1][0] = val[1][1];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            for(int len = 0; len <= k; ++len){
                if(len > 0 and j > 1)
                    dp[i][j][len] = max(dp[i][j][len], dp[i][j - 1][len - 1] + val[i][j]);
                if((len == 0 or len == k) and a[i][j] == '.' and j > 1)
                    dp[i][j][len] = max(dp[i][j][len], dp[i][j - 1][len] + val[i][j]);
                if(len > 0 and i > 1)
                    dp[i][j][len] = max(dp[i][j][len], dp[i - 1][j][len - 1] + val[i][j]);
                if((len == 0 or len == k) and a[i][j] == '.' and i > 1)
                    dp[i][j][len] = max(dp[i][j][len], dp[i - 1][j][len] + val[i][j]);
            }
            // cout << dp[i][j][3] << " ";
        }
        // cout << endl;
    }
    ll ans = INT_MIN;
    for(int i = 0; i <= k; ++i)
        ans = max(ans, dp[n][n][i]);
    cout << (ans < 0 ? -1 : ans) << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
    // you should actually read the stuff at the bottom
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * Read other problems if stuck on this one.
*/
