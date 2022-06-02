#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 998244353;
long long fact[N];

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
ll sub(ll a, ll b){
    return((a % MOD - b % MOD + MOD) % MOD);
}
ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}
ll divi(ll a, ll b){
    return(mul(a, power(b, MOD - 2)) % MOD);
}

long long nCr(int n, int r){
    if(r == 0)
        return 1;
    if(n < r) return 0;
    return (divi(fact[n], (fact[r] * fact[n-r])) % MOD);
}

void solve(){
    long long n;
    cin >> n;
    long long a[n + 1];
    map<int, int> cnt;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    long long ans = fact[n];
    if(a[n] == a[n - 1]){
        cout << ans << '\n';
        return;
    }
    if(a[n] != a[n - 1] + 1){
        cout << 0 << '\n';
        return;
    }
    long long x = nCr(n, cnt[a[n - 1]] + 1) % MOD;
    x = (x * fact[cnt[a[n -  1]]]) % MOD;
    x = (x * fact[n - cnt[a[n - 1]] - 1]) % MOD;
    cout << ((ans - x)%MOD + MOD) % MOD << '\n'; 
}

int main(){
    fast;
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; ++i)
        fact[i] = (fact[i - 1] * i) % MOD;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
