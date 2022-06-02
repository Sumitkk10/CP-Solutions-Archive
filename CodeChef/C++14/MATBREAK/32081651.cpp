#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
ll MOD = 1e9 + 7;

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

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, a;
        cin >> n >> a;
        ll sum = 0, p = a, mul = 1;
        for(int i = 1; i <= ((n-1)+n); i += 2){
            mul = power(p, i);
            //cout << p << " " << i << " " << mul << endl;    
            sum = ((sum%MOD)+(mul%MOD))%MOD;
            p = ((p % MOD) * (mul % MOD)) % MOD;
        }
        cout << sum << '\n';
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
    