#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n, k, s, a[N], pre_sum[N], dp[N][22];

void solve(){
    cin >> n >> k >> s;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    pre_sum[0] = 0;
    for(int i = 1; i <= n; ++i)
        pre_sum[i] = pre_sum[i - 1] + a[i];
    for(int i = 1; i <= n; ++i){
        int low = i, high = n, res = i;
        while(low <= high){
            int mid = (low + high) / 2;
            if(pre_sum[mid] - pre_sum[i - 1] <= s){
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        dp[i][0] = res + 1;
    }
    dp[n + 1][0] = n + 1;
    for(int jump = 1; jump <= 20; ++jump)
        for(int i = 1; i <= n + 1; ++i)
            dp[i][jump] = dp[dp[i][jump - 1]][jump - 1];
    ll ans = 0;
    for(ll i = 1; i <= n; ++i){
        ll cur = i;
        for(ll jump = 20; jump >= 0; --jump)
            if(k & (1LL << jump))
                cur = dp[cur][jump];
        ans = max(ans, cur - i);
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
