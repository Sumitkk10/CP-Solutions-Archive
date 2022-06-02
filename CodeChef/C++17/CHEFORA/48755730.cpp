#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 100003;
vector<long long> num, pre(N, 0);

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

void solve(){
    int l, r;
    cin >> l >> r;
    long long exponent = pre[r - 1] - pre[l - 1];
    long long ans = mod_expo(num[l - 1], exponent);
    cout << ans << '\n';
}
 
int main() {
    fast;
    for(int i = 1; i < N; ++i){
        string s = to_string(i);
        int extract = s.size() - 1;
        string cur;
        for(int j = extract - 1; j >= 0; --j) cur.push_back(s[j]);
        s += cur;
        long long x = stoll(s);
        num.push_back(x);
    }
    pre[0] = num[0];
    for(int i = 1; i < N; ++i)
        pre[i] = pre[i - 1] + num[i];
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}