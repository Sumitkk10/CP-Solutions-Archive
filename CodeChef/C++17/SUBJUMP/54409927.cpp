#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 3;
const int MOD = 1e9 + 7;
long long n, a[N];
vector<ll> cur_dp(N);

long long C(ll x, ll xx){
    if(xx < x) return LLONG_MAX;
    if(xx == x) return 0;
    ll ans = ((xx - x + 1) * a[x]) - a[xx];
    return ans;
}

void compute(int l, int r, int optl, int optr) {
    if (l > r)
        return;
    int mid = l;
    long long best = cur_dp[optl] + C(optl, mid), idx = optl;
    if(best > cur_dp[l - 1] + C(l - 1, mid)){
        best = cur_dp[l - 1] + C(l - 1, mid);
        idx = l - 1;
    }
    if(cur_dp[mid] < best)
        idx = mid;
    else
        cur_dp[mid] = best;
    compute(mid + 1, r, idx, optr);
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cur_dp[1] = 0;
    for(int i = 2; i <= n; ++i)
        cur_dp[i] = C(1, i);
    compute(2, n, 1, n);
    cout << max(0ll, cur_dp[n]) << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}