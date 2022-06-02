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
    ll a[n];
    map<ll, ll> mp;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    for(auto k : mp)
        ans += (k.second * (k.second - 1));
    cout << (n*(n - 1)) - ans << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
