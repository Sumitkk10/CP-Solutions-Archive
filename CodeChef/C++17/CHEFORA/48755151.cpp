#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 100003;

ll mod_expo(ll x, ll y){
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

int main() {
    fast;
    vector<long long> num, pre(N, 0);
    int i = 1;
    while(i < N){
        int cur = i / 10;
        long long x = i;
        while(cur > 0){
            x *= 10;
            x += (cur % 10);
            cur = cur / 10;
        }
        num.push_back(x);
        ++i;
    }
    pre[0] = num[0];
    for(int i = 1; i < N; ++i)
        pre[i] = pre[i - 1] + num[i];
    int t = 1;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        long long exponent = pre[r - 1] - pre[l - 1];
        long long ans = mod_expo(num[l - 1], exponent);
        cout << ans << '\n';
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}