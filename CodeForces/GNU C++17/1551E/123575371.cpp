#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1e9));
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
    }
    dp[0][0] = 0;
    // dp[i][j] denotes no. of good positions in the prefix of i if i do j moves.
    for(int i = 0; i < n; ++i){
        for(int dec = 0; dec < n; ++dec){
            if(dp[i][dec] < 0) continue;
            dp[i + 1][dec] = max(dp[i + 1][dec], dp[i][dec] + (a[i] == i - dec));
            if(dec + 1 < n)
                dp[i + 1][dec + 1] = max(dp[i + 1][dec + 1], dp[i][dec]);
        }
    }
    for(int i = 0; i < n; ++i){
        if(dp[n][i] >= k){
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
