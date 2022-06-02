#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    ll n;
    cin >> n;
    string s[n + 1];
    ll bits[n + 1];
    memset(bits, 0, sizeof bits);
    for(int i = 1; i <= n; ++i)
        cin >> s[i];
    for(int i = 1; i <= n; ++i){
        map<char, int> mp;
        for(auto k : s[i])
            mp[k]++;
        for(int j = 0; j < 26; ++j){
            char x = (char) j + 'a';
            bits[i] += (mp[x] % 2 == 1 ? (1 << j) : 0);
        }
    }
    map<ll, ll> cnt;
    for(int i = 1; i <= n; ++i)
        cnt[bits[i]]++;
    ll ans = 0;
    for(auto k: cnt)
        ans += (k.second * (k.second - 1));
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 26; ++j){
            ll cur = bits[i];
            // remove this bit
            cur = (cur ^ (1 << j));
            ans += (cnt[cur]);
        }
    }
    cout << ans / 2 << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
