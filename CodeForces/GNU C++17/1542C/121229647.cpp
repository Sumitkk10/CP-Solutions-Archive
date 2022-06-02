#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long n;
    cin >> n;
    long long lcm = 2, ans = 2*((n+1)/2), cur = (n + 1)/2;
    ans = (ans % MOD);
    for(long long i = 3; i <= 130; ++i){
        long long ok = n / lcm, okk =  ((lcm * i) / __gcd(lcm, i));
        long long k = n / okk;
        ans = (ans + (((ok - k) * i) % MOD)) % MOD;
        lcm = ((lcm * i) / __gcd(lcm, i));
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
