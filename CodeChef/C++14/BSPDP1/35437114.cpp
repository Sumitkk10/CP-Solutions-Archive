#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e3 + 2;
ll n, a[N], mx = -1e9, dp[N][N];

ll go(ll i, ll k){
    if(k == 0 || i >= n) return 0;
    if(dp[i][k] != -1) return dp[i][k];
    ll c = 0, b = 0;
    if(i + 1 < n)
        c = go(i+1, k-1) + a[i+1];
    if(i + 1 < n)
        b = go(i+2, k-1) + a[i+2];
    return dp[i][k] = max(0ll ,max(c, b));
}

int main(){
    fast;
    ll k;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        mx = max(mx, go(i, k-1) + a[i]);
    cout << mx;
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}