#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7, MOD1 = 1e9 + 6;
ll lengths[N], ones[N];

ll power(ll x, ll y){
    x %= MOD;
    ll ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    ll x = ones[n];
    ll p = power(2, (lengths[n] - 1) % MOD1);
    cout << (x * p) % MOD << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    lengths[0] = 1;
    ones[0] = 0;
    lengths[1] = 1;
    ones[1] =1 ;
    for(int i = 2; i < N; ++i){
        lengths[i] = (lengths[i - 1] + lengths[i - 2]) % MOD1;
        ones[i] = (ones[i - 1] + ones[i - 2]) % MOD;
    }
    // cout << lengths[5] << " " << ones[5] << "\n";
    while(t--)
        solve();
    return 0;
}
