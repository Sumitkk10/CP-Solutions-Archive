#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define S second
#define F first
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    ll d, n, k;
    cin >> d >> n >> k;
    pair<ll, pair<ll, ll> > a[n + 1];
    // will last from 1 to day d
    for(int i = 1; i <= n; ++i)
        cin >> a[i].F >> a[i].S.F >> a[i].S.S;
    sort(a + 1, a + n + 1, greater<pair<ll, pair<ll, ll> > >());
    ll ans = 0;
    for(int i = 1; i <= d; ++i){
        int ct = 0;
        ll cur = 0;
        for(int j = 1; j <= n; ++j){
            if(ct >= k)
                break;
            if(a[j].S.F <= i and a[j].S.S >= i){
                cur += a[j].F;
                ct++;
            }
        }
        ans = max(ans, cur);
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