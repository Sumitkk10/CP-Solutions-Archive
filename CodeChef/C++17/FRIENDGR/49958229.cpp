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
    string s;
    cin >> s;
    s = " " + s;
    int pre = -1;
    long long dp[n + 1][3];
    dp[0][1] = 0;
    dp[0][0] = 0;
    dp[0][2] = 0;
    for(int i = 1; i <= n; ++i){
        if(s[i] == '0'){
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
            continue;
        }
        if(pre == -1){
            pre = i;
            dp[i][0] = 1;
            dp[i][1] = 1;
            dp[i][2] = 1;
            continue;
        }
        int x = i;
        dp[i][0] = dp[i][1] = dp[i][2] = INT_MAX;
        // ok so x is the current location and i - 1 is the i - 1vious one.
        // now if I do not move this interval then I have to move the i - 1vious interval right.
        if(x - pre - 1 <= k)
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if(x - pre <= k)
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if(x - pre + 1 <= k)
            dp[i][0] = min(dp[i][0], dp[i - 1][2]);
        dp[i][0] = min({dp[i][0], dp[i - 1][1] + 1, dp[i - 1][2] + 1, dp[i - 1][0] + 1});
        // now I move this interval to the left;
        if(x - pre - 1 <= k)
            dp[i][2] = min({dp[i][2], dp[i - 1][0], dp[i - 1][1]});
        if(x - pre - 2 <= k)
            dp[i][2] = min(dp[i][2], dp[i - 1][1]);
        if(x - pre <= k)
            dp[i][2] = min(dp[i - 1][2], dp[i - 1][2]);
        dp[i][2] = min(dp[i][2], min({dp[i - 1][2], dp[i - 1][1], dp[i - 1][0]}) + 1);
        // now I move the interval to the right;
        if(x - pre + 1 <= k)
            dp[i][1] = dp[i - 1][0];
        if(x - pre <= k)
            dp[i][1] = min(dp[i][1], dp[i - 1][1]);
        if(x + 2 - pre <= k)
            dp[i][1] = min(dp[i][1], dp[i - 1][2]);
        dp[i][1] = min(dp[i][1] ,min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1);
        pre = i;
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}