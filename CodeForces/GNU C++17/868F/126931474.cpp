#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
ll n, k, a[N], l = 1, r, mp[N], ans;
vector<ll> cur_dp(N), dp_before(N);

long long cost(int i, int j){
    while(l > i){
        --l;
        ans += mp[a[l]];
        mp[a[l]]++;
    }
    while(l < i){
        mp[a[l]]--;
        ans -= mp[a[l]];
        ++l;
    }
    while(r < j){
        ++r;
        ans += mp[a[r]];
        mp[a[r]]++;
    }
    while(r > j){
        mp[a[r]]--;
        ans -= mp[a[r]];
        --r;
    }
    return ans;
}

void dnc(int l, int r, int optl, int optr){
    if(l > r) return;
    int mid = (l + r) >> 1;
    ll mn = 1e14, idx;
    for(int i = optl; i <= min(mid, optr + 1); ++i){
        int x = cost(i + 1, mid);
        if(mn > dp_before[i] + x){
            mn = dp_before[i] + x;
            idx = i;
        }
    }
    cur_dp[mid] = mn;
    dnc(l, mid - 1, optl, idx);
    dnc(mid + 1, r, idx, optr);
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
     dp_before[0] = 0;
    for(int i = 1; i <= n; ++i){
        dp_before[i] = dp_before[i - 1];
        mp[a[i]]++;
        dp_before[i] += mp[a[i]] - 1;
    }
    for(int i = 1; i <= n; ++i)
        mp[i] = 0;
    for(int j = 1; j < k; ++j){
        dnc(1, n, 1, n);
        dp_before = cur_dp;
    }
    cout << dp_before[n] << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
