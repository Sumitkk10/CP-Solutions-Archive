#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    ll n;
    cin >> n;
    ll a[n + 1][3], ans = INT_MAX, pre_sum[n + 2][3];
    pre_sum[0][1] = pre_sum[n + 1][2] = 0;
    for(int i = 1; i <= n; ++i)
        cin >> a[i][1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i][2];
    for(int i = n; i >= 1; --i)
        pre_sum[i][2] = pre_sum[i + 1][2] + a[i][1];
    for(int i = 1; i <= n; ++i)
        pre_sum[i][1] = pre_sum[i - 1][1] + a[i][2];
    for(int i = 1; i <= n; ++i)
        ans = min(ans, max(pre_sum[i + 1][2], pre_sum[i - 1][1]));
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
