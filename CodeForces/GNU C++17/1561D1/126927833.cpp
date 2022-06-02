#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n, M, dp[N];

void solve(){
    cin >> n >> M;
    ll pre = 0;
    dp[n] = 1;
    for(int i = n; i >= 1; --i){
        dp[i] = (dp[i] + pre) % M;
        for(int j = 2; j <= sqrt(i); ++j){
            int cur = i / j;
            dp[cur] = (dp[cur] + dp[i]) % M;
        }
        int ok = (i / (int) (sqrt(i) + 1));
        for(int j = ok; j >= 1; --j){
            int cur = i / j;
            int cur1 = i / (j + 1);
            dp[j] = (dp[j] + (cur - cur1)*dp[i]) % M;
        }
        pre = (pre + dp[i]) % M;
    }
    /*
    for(int i = 1; i <= n; ++i)
        cout << dp[i] << " ";
    */
    cout << dp[1] << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
