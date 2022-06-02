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

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cur_dp[1] = 0;
    ll idx = 1;
    for(int i = 2; i <= n; ++i){
    	cur_dp[i] = cur_dp[idx] + C(idx, i);
    	if(cur_dp[i - 1] + C(i - 1, i) < cur_dp[i]){
    		idx = i - 1;
    		cur_dp[i] = cur_dp[i - 1] + C(i - 1, i);
    	}
    	if(C(1, i) < cur_dp[i]){
    		cur_dp[i] = C(1, i);
    		idx = 1;
    	}
    }
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