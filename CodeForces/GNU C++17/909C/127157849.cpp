#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 5e3 + 1;
const int MOD = 1e9 + 7;
int n;
char s[N];
ll dp[N][N];

ll go(int i, int lvl){
    if(i == n - 1)
        return 1;
    if(dp[i][lvl] != -1)
        return dp[i][lvl];
    ll ans = 0;
    if(s[i] == 'f')
        ans = (ans + go(i + 1, lvl + 1)) % MOD;
    else{
        ans = (ans + go(i + 1, lvl)) % MOD;
        if(lvl)
            ans = (ans + go(i, lvl - 1)) % MOD;
    }
    return dp[i][lvl] = ans;
}

void solve(){
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    cout << go(0, 0) << "\n";
}

int main(){
    fast;
    int t = 1;
    while(t--)
        solve();
    return 0;
}
