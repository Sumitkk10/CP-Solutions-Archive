#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
long long pre_sum[N], dp[N][450];

void solve(){
    long long n;
    cin >> n;
    long long a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    pre_sum[0] = 0;
    for(int i = 1; i <= n; ++i)
        pre_sum[i] = pre_sum[i - 1] + a[i];
    long long low = 1, high = n, k = 1;
    while(low <= high){
        long long mid = (low + high) / 2;
        if((mid * (mid + 1)) / 2 <= n){
            k = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    for(int i = 0; i <= n + 1; ++i){
        dp[i][0] = 0;
        for(int j = 1; j <= k; ++j)
            dp[i][j] = INT_MIN;
    }
    dp[n + 1][1] = 0;
    for(int i = n; i >= 1; --i)
        dp[i][1] = max(a[i], dp[i + 1][1]);
    int ans = 1;
    for(int j = 2; j <= k; ++j){
        for(int i = n; i >= 1; --i){
            if(i + j - 1 <= n and dp[i + j][j - 1] > 0 and pre_sum[i + j - 1] - pre_sum[i - 1] < dp[i + j][j - 1]){
                dp[i][j] = max(dp[i + 1][j], pre_sum[i + j - 1] - pre_sum[i - 1]);
            }
            else
                dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        }
        if(dp[1][j] >= 0)
            ans = max(ans, j);
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
