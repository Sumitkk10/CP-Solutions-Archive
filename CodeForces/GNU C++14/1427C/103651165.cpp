#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
    fast;
    int r, n;
    cin >> r >> n;
    int dp[n + 1] = {0};
    int x[n + 1], y[n + 1], t[n + 1] = {0}, ans[n + 1] = {0};
    x[0] = y[0] = 1;
    for(int i = 1; i <= n; ++i){
        cin >> t[i] >> x[i] >> y[i];
        dp[i] = INT_MIN;
        for(int j = max(0, i - (2 * r)); j < i; ++j)
            if(abs(x[j] - x[i]) + abs(y[j] - y[i]) <= t[i] - t[j])
                dp[i] = max(dp[i], dp[j] + 1);
        if(i > 2*r)
            dp[i] = max(dp[i], 1 + ans[i - 2*r]);
        ans[i] = max(ans[i - 1], dp[i]);
    }
    cout << ans[n] << '\n';
    return 0;
}
          