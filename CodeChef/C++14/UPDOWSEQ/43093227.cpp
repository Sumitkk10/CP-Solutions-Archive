#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N];

void solve(){
    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    int pre_dp[n + 1][2], suf_dp[n + 1][2];

    // 0 --> ending down

    // 1 --> ending up

    pre_dp[1][0] = pre_dp[1][1] = 1;

    for(int i = 2; i <= n; ++i){
        pre_dp[i][0] = pre_dp[i][1] = 1;

        // our seq is currently ending here

        // condition for ending down :

        if(a[i - 1] >= a[i])
            pre_dp[i][0] = pre_dp[i - 1][1] + 1;

        // condition for ending upwards :

        if(a[i - 1] <= a[i])
            pre_dp[i][1] = pre_dp[i - 1][0] + 1;
    }

    suf_dp[n][0] = suf_dp[n][1] = 1;

    for(int i = n - 1; i >= 1; --i){

        suf_dp[i][0] = suf_dp[i][1] = 1;

        // our seq is starting from here.

        // condition for starting down :

        if(a[i + 1] >= a[i])
            suf_dp[i][0] = suf_dp[i + 1][1] + 1;

        // condition for starting up :

        if(a[i + 1] <= a[i])
            suf_dp[i][1] = suf_dp[i + 1][0] + 1;
    }

    int ans = 0;	

    for(int i = 1; i <= n - 1; ++i){
        if(pre_dp[i][0] % 2 == 0)
        	ans = max(ans, pre_dp[i][0] + suf_dp[i + 1][0]);
        else
        	ans = max(ans, pre_dp[i][0] + suf_dp[i + 1][0] + 1);
        if(pre_dp[i][1] % 2)
        	ans = max(ans, pre_dp[i][1] + suf_dp[i + 1][1]);
        else
        	ans = max(ans, pre_dp[i][1] + suf_dp[i + 1][1] + 1);
   }

    cout << ans << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}