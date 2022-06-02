#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1000000 + 5;
const int MOD = 1e9 + 7;
long long int n, a[N], k, pre_sum[N], dp[N], dp1[N];

int main() {
    fast;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre_sum[i] = pre_sum[i - 1] + a[i];
    }
    for(int i = 1; i <= n; ++i)
        dp1[i] = max(0LL, max(dp1[i - 1] + a[i], a[i]));
    long long int ans = INT_MIN;
    for(int i = k; i <= n; ++i){
        dp[i] = pre_sum[i] - pre_sum[i - k] + dp1[i - k];
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}
