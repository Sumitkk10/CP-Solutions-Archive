#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

string dec(ll x){
    string ans;
    while(x > 1){
        ans.push_back((x % 2 == 1 ? '1' : '0'));
        x /= 2;
    }
    ans.push_back('1');
    reverse(ans.begin(), ans.end());
    return ans;
}

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

ll ad(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}

void solve(){
    ll n, k;
    cin >> n >> k;
    string s = dec(k);
    ll ans = 0, j = 0;
    for(int i = s.size() - 1; i >= 0; --i){
        if(s[i] == '1')
            ans = ad(ans, power(n, j));
        ++j;
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
